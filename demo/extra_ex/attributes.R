### SHELL> mpiexec -np 4 Rscript Read_demo.R

library(pbdADIOS, quiet = TRUE)

adios.read.init.method("ADIOS_READ_METHOD_BP", params="verbose=3")
timeout.sec <- 1.0

file <- "attributes.bp"
file.ptr <- adios.read.open(file, "ADIOS_READ_METHOD_BP",
                                  adios.lockmode="ADIOS_LOCKMODE_NONE",
                                  adios.timeout.sec=timeout.sec)  

adios.attr.read(adios.fp=file.ptr)
barrier()
adios.var.attr.read(adios.fp=file.ptr) 
barrier()

adios.read.close(file.ptr)
barrier()
adios.read.finalize.method("ADIOS_READ_METHOD_BP")

finalize()