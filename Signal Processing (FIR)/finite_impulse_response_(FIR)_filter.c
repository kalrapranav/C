 #define SIZE 579

//double readSignal_dat();
void main(void)
{
    FILE *fPtr;
    if ((fPtr = fopen("signal.dat", "r")) == NULL)
    {
        puts("File could not be opened");
    }
    else
    {
        double sample;
        static double x[SIZE];
        size_t i = 0;
        while (!feof(fPtr))
        {

            fscanf(fPtr, "%lf", &sample);
            printf("%d = %7.3f  ",i, sample);
            x[i] = sample;
            printf("x[%d] = %lf\n", i, x[i]);
            i = i + 1;
        }
        fclose(fPtr);
        printf("------------------------------------------------------------------\n");
  int n = (SIZE - 1);
   double b;
   double y[SIZE];
   const int N = 100;

   double denominator;
   for(size_t p = 0; p < SIZE; p++)
   {
       denominator = (100+1);
       b = 1 / denominator;
       int index = (n - p);
       y[p] = b * x[index];
       printf("N = %d, n = %d, b = %lf,x[%d] = %lf, y[%d] = %lf, (100 + 1) = 101; %lf\n",
              N,n,b,p,x[p],p,y[p],denominator);
      n = n-1;
   }
        printf("------------------------------------------------------------------\n");
        for(size_t i = 0; i < SIZE; i++)
   {
       printf("y[%d] = %lf\n", i, y[i]);
   }
   printf("-------------------------------------------------------------------------\n");
   for(size_t i = 0; i < SIZE; i++)
   {
       printf("%d %lf\n",i, y[i]);
   }


    }

}


