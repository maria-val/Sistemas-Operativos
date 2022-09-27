struct thread {
	double x1;
	double x2;
	long nstep;
	double (*f)(double);
	double tam_trap;
	long nstep_hilo;
	int nthreads;
};

int integra_trap_th(double *result, double x1, double x2, long nstep, int nthreads, double(*f)(double));
