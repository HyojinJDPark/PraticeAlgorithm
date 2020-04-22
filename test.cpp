#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;

int main()
{
	int number_of_testcase = 0;
	int x0y0x1y1[4] = {0,};
	int n = 0;
	float pi = (1 + sqrt(5)/2);

	while(1)
	{
		cin >> number_of_testcase;

		if( number_of_testcase > 10 ) continue;
		
		for(char i = 0; i < number_of_testcase ; i++)
		{
			for(char j = 0; j < 4; j++)
			{
				while(true)
				{
					int num = 0;
					
					scanf("%d",&num );

					if(num > 1000000000 ) continue;

					x0y0x1y1[j] = num;

					break;
				}

			}
		}

		break;
	}

	cout<<"n is "<<n<<" pi is "<<pi<<endl;	

	return 0;
}
