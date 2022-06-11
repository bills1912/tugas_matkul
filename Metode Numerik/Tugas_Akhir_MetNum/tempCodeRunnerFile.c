for(i=0;i< n;i++)
      {
            if (fabs(x_diff - x[i])< 0.000001)
            {
                  index = i;
                  flag = 1;
                  break;
            }
      }

      if (flag==0)
      {
            printf("Nilai x yang dimasukkan tidak valid. Keluar dari program!");
            exit(0);
      }