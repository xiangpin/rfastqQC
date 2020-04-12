#' @title Quality Statistics
#' @param samplename character, the sample names
#' @param files character, the path of fastq file.
#' @param type character, the prefix of output, eg:rawR1 or rawR2
#' @author Shuangbin Xu
#' @export
StatRead <- function(samplename, files, type=NULL){
    res <-  StatRead_cpp(sample=samplename, readfile=files, Type=type)
    tmpnames <- names(res)
    res <- data.frame(matrix(unlist(res), nrow=1))
    colnames(res) <- tmpnames
    return(res)
}

rbindReads <- function(reslist){
	resTab <- as.data.frame(do.call("rbind", reslist), 
				check.names=FALSE)
	tmp <- colnames(resTab)[2:(ncol(resTab)-1)] 
	type <- unique(as.vector(resTab$Type))
	colnames(resTab)[2:(ncol(resTab)-1)] <- paste0(tmp,"(",type,")")
	resTab$Type <- NULL
	return(resTab)
}

#readsda <- read.table(readsfile, header=T)
#configda <- read.table(config, sep="=", header=F)
#rawdapath <- as.character(configda[configda$V1=="datapath",2])
#cleanpath <- as.character(configda[configda$V1=="cleandatapath",2])
#
#rawda <- tidyr::separate(readsda, 2, c("R1", "R2"), sep=";")
#rawda$R1 <- paste0(rawdapath, "/", as.vector(rawda$R1))
#rawda$R2 <- paste0(rawdapath, "/", as.vector(rawda$R2))
#
#cleanda <- data.frame(samples=as.vector(readsda[,1]), 
#			 files=paste0(cleanpath,"/",as.vector(readsda[,1]),"_clean_merge.fastq"))
#
#
#rawR1 <- apply(rawda, 1, function(x){ReadStat(x[1], x[2], "R1")})
#rawR2 <- apply(rawda, 1, function(x){ReadStat(x[1], x[3], "R2")})
#cleandat <- apply(cleanda, 1, function(x){ReadStat(x[1], x[2], "CleanTag")})
#
#rawR1 <- rbindReads(rawR1)
#rawR2 <- rbindReads(rawR2)
#cleandat <- rbindReads(cleandat)
#totalda <- data.frame(merge(merge(rawR1, rawR2, sort = FALSE), 
#		   cleandat, sort = FALSE), check.names=FALSE)
#
#openxlsx::write.xlsx(totalda, output, row.names=FALSE)

