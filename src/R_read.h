#ifndef __R_READ__
#define __R_READ__

int schedule_read (ADIOS_FILE * fp, 
                  const char *varname,
                  int* start, 
                  int s_length,
                  int* count,
                  int c_length,
                  void ** data,
                  ADIOS_SELECTION ** sel,
                  ADIOS_VARINFO ** vi,
                  uint64_t p,   //number of ranks
                  uint64_t rank);

SEXP copy_read (SEXP R_adios_var_info, 
                SEXP R_nelems, 
                SEXP R_data);

SEXP R_read(SEXP R_adios_path,
            SEXP R_varname,
            SEXP R_start,
            SEXP R_count,
            SEXP R_nvars,
            SEXP R_comm,
            SEXP R_p,
            SEXP R_adios_rank);

#endif