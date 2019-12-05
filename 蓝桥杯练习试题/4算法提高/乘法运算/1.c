#include<stdio.h>
int main()
{
	int i;
	struct map
	{
		char a[10]; //国家
		float area;  //面积
		float pop;  //人口
		float GDP;  //GDP 
	};
	
	struct map m[5]={{"China",       960.00,  129500.00,  1080.00  },
	                 {"Iceland",     10.30,   27.57,      8.20     },
	                 {"India",       297.47,  97000.00,   264.80   },
	                 {"Madagascar",  62.70,   1635.00,    3.60     },
	                 {"Maldive",     0.0298,  27.80,      0.23     }
	    };
	printf("------------------------------------------------------------------------------\n");
	printf("COUNTRY AREA(10K km2) POP.(10K) GDP(Billion$)\n");
	printf("------------------------------------------------------------------------------\n");
	for(i=0;i<4;i++)
	printf("%s %.2f %.2f %.2f\n",m[i].a,m[i].area,m[i].pop,m[i].GDP);
	printf("%s %.4f %.2f %.2f\n",m[i].a,m[i].area,m[i].pop,m[i].GDP);
	printf("-----------------------------------------------------------------------------\n");
	
}
