	}

      else

	{

	  printf ("File in the index is already allocated \n");

	}
    }

  printf ("\nAllocated Blocks\nFile\tIndex\tLength\n");

  for (int i = 0; i < allocated; i++)

    {

      printf ("%d\t%d\t%d\n", alocfil[i][0], alocfil[i][1], alocfil[i][2]);

    }
}

void
seq ()
{

  int files[200], alocfiles[32][3];

  int startBlock, len, j, k, ch, allocated = 0;

  int n;

  for (int i = 0; i < 200; i++)

    files[i] = 0;

  printf ("Enter the number of files...\n");

  scanf ("%d", &n);

  for (int i = 0; i < n; i++)

    {

      int flag = 0;

      printf ("Enter the starting block and the length of the file %d:  ",
	      i + 1);

      scanf ("%d%d", &startBlock, &len);

      for (j = startBlock; j < (startBlock + len); j++)
	{

	  if (files[j] == 0)

	    flag++;

	}

      if (len == flag)
	{

	  for (int k = startBlock; k < (startBlock + len); k++)
	    {

	      if (files[k] == 0)
		{

		  files[k] = 1;

		}

	    }

	  printf ("The file %d is allocated to the disk\n", i + 1);

	  alocfiles[allocated][0] = i + 1;

	  alocfiles[allocated][1] = startBlock;

	  alocfiles[allocated][2] = len;

	  allocated++;

	}

      else

	printf ("The file %d is not allocated to the disk\n", i + 1);

    }

  printf ("\nAllocated Files:\n\nFile No\tStart Block\tLength\n");

  for (int i = 0; i < allocated; i++)

    {

      printf ("%d\t%d\t\t%d\n", alocfiles[i][0], alocfiles[i][1],
	      alocfiles[i][2]);

    }
  int filno;

  printf ("\nEnter File Number: ");

  scanf ("%d", &filno);

  for (int i = 0; i < allocated; i++)

    {

      if (alocfiles[i][0] == filno)

	{
	  printf ("File Number : %d\t Space Occupied : %d\n", alocfiles[i][0],
		  alocfiles[i][2]);

	  filno = -1;

	}

    }

  if (filno != -1)

    printf ("File Number Not Found!\n\n");

  return;

}



int
main ()
{
  printf ("File Allocations");

  int op = 0;

  while (op != 4)

    {

      printf
	("\n\n1. SEQUENTIAL\n2. INDEXED\n3. LINKED\n4. Exit\nEnter your option...\n\n");

      scanf ("%d", &op);

      switch (op)

	{

	case 1:

	  seq ();

	  break;

	case 2:

	  indexed ();

	  break;

	case 3:

	  linked ();

	  break;

	}

    }

}
