
#include <iostream>
#include <cstdlib>
#include<string>
#define CITIES 8

using namespace std;
int num_Sol(int s);

void exhaustive_enmeration();
//int num_City = 8;


int main(void)
{
	
	//cout << "today try the exhaustive enumeration" << endl;

	num_Sol(CITIES);

	cout << endl;
	exhaustive_enmeration();

	system("pause");
	return 0;
}

void exhaustive_enmeration()
{
	int min;
	cout << " Input the min of distance : " << endl;
	cin >> min;
	//min = 10;
	int max;
	cout << " Input the Max of distance : " << endl;
	cin >> max;
	//max = 90;
	cout << endl;
	int route_Cities[8][8];
	//int x = rand() % (max - min + 1) + min;
	for (int i = 0; i < CITIES; i++)
	{
		for (int j = 0; j < CITIES; j++)
		{
			if (i < j)
				route_Cities[i][j] = rand() % (max - min + 1) + min;
			if (i == j)
				route_Cities[i][j] = 0;
			route_Cities[j][i] = route_Cities[i][j];
			cout << route_Cities[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	int curr_Distance = 0;
	int leg01, leg02, leg03, leg04,leg05,leg06,leg07,leg08;
	
	int shorest_Dis = 1000;

	//**************the iterations which important part*************************
	for (int a = 1; a < CITIES; a++)
	{
		
		leg01 = curr_Distance;
		leg01 += route_Cities[0][a];
		//cout <<"Tier1*: "<< leg01 << endl;
		for (int b = 1; b < CITIES; b++)
		{
			leg02 = leg01;
			if (a == b)
				leg02 -= 1000;
			if(a!=b)
				leg02 += route_Cities[a][b];
			if(leg02 >0)
				//cout << "Tier2**: " << leg02 << endl;
			for (int c = 1; c < CITIES; c++)
			{
				leg03 = leg02;
				if (b != c && a != c)
					leg03 += route_Cities[b][c];
				else
					leg03 -= 1000;
				
				if (leg03 > 0)
					//cout << "Tier3***: "<< leg03 << endl;
				
				for (int d = 1; d < CITIES; d++)
				{
					leg04 = leg03;
					if (c != d && b != d && a != d)
						leg04 += route_Cities[c][d];
					else
						leg04 -= 1000;
					if (leg04 > 0)
						//cout << "Tier4****: " << leg04 << endl;
					for (int e = 1; e < CITIES; e++)
					{
						leg05 = leg04;
						if (d != e && c != e && b != e && a != e)
							leg05 += route_Cities[d][e];
						else
							leg05 -= 1000;
						if (leg05 > 0)
							//cout << "Tier5*****: " << leg05 << endl;
						for (int f = 1; f < CITIES; f++)
						{
							leg06 = leg05;
							if (e != f && d != f && c != f && b != f && a != f)
								leg06 += route_Cities[e][f];
							else
								leg06 -= 1000;
							if (leg06 > 0)
								//cout << "Tier6******: " << leg06 << endl;
							for (int g = 1; g < CITIES; g++)
							{
								leg07 = leg06;
								if (f != g && e != g && d != g && c != g && b != g && a != g)
									leg07 += route_Cities[f][g];
								else
									leg07 -= 1000;
								if (leg07 > 0)
									//cout << "Tier7*******: " << leg07 << endl;
								for (int h = 0; h < CITIES; h++)
								{
									leg08 = leg07;
									if (a != h && b != h && c != h && d != h && e != h && f != h && g != h)
										leg08 += route_Cities[g][h];
									else
										leg08 -= 1000;
									if (leg08 > 0)
										//cout << "Tier8********: " << leg08 << endl;
									if (leg08 < shorest_Dis && leg08 > 0)
										shorest_Dis = leg08;
								}
							}
						}
					}
					
				}
			}
			

			//if (leg04 < shorest_Dis && leg04>0)    RECORD IT AS HOW TO MAKE THE SHOREST DISTANCE
				//shorest_Dis = leg04;
			curr_Distance = 0;
		}
		
	
	}
	cout << "shorest Distance is : " << shorest_Dis << endl;




	return;

}




int num_Sol(int s)  // compute the number of solutions 
{
	int temp_rest_Route = 1;
	for (int j = 1; j < s; j++)
	{
		temp_rest_Route *= j;
	}
	//cout << "the total number of solutions: " << temp_rest_Route << endl;
	return temp_rest_Route;
}




