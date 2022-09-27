struct procesos {
	double x1;
	double tam_trap;
	long div_pkg;
	double (*f)(double);
};

void dispatcher( int workpipe, int numwp, long ndiv);
void worker( int workpipe, int resultpipe);
void gatherer( int resultpipe);
