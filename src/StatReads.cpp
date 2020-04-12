#include <Rcpp.h>
#include <fstream>
using namespace Rcpp;

//--------------------------------
// @param sample The sample name.
// @param readfile The path of reads file, only uncompressed fastq file is supported.
// @param Type The type of fastq file. 'raw' or 'clean'.
//
// @return A list, contained Q20, Q30, GC, average length and total base of the sample fastq file.

// [[Rcpp::export]]
Rcpp::List StatRead_cpp(std::string sample, std::string readfile, Nullable<StringVector> Type=R_NilValue){
    int num=0;
    double total_base=0;
    double q20_num=0;
    double q30_num=0;
    double gc_num=0;
    std::ifstream inputfile(readfile.c_str());
    inputfile.get();
    for (std::string line; std::getline(inputfile, line);){
        num += 1;
        if(num%4==0){
            int len=line.size();
            for (int i=0; i<len; i++){
                int ord = line[i];
                if ((ord - 33) >= 20){
                    q20_num += 1;
                }
                if ((ord - 33) >= 30){
                    q30_num += 1;
                }
            }
        }
        if (num % 4 == 2){
            total_base += line.size();
            gc_num += count(line.begin(), line.end(),'G');
            gc_num += count(line.begin(), line.end(), 'C');
        }
    }
    double Q20 = R::fround(100*q20_num/total_base, 2);
    double Q30 = R::fround(100*q30_num/total_base, 2);
    double GC = R::fround(100*gc_num/total_base, 2);
    double length = R::fround(total_base/(num/4), 0);
    List df = List::create(Named("sample")=sample,
                           Named("Q20%")=Q20,
                           Named("Q30%")=Q30,
                           Named("GC%")=GC,
                           Named("AveLen[bp]")=length,
                           Named("TotalBase[bp]")=total_base);
    if (Type.isNotNull()){
        df["Type"] = Type;
    }
    return wrap(df);
}
