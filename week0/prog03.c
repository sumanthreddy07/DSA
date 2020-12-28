//program to find the square root of a number using binary search

#include <stdio.h>



int main()
{
	float number;
	
	printf("Enter the number whose square root is to be found: ");
	scanf("%f",&number);

        int start=0,end;

        int mid;

        float ans;

        end=number;
        while(start<=end)
        {
                mid=(start+end)/2;
                if(mid*mid==number)
                {
                        ans=mid;
                        break;
                }
                if(mid*mid<number)
                {
                        start=mid+1;
                        ans=mid;
                }
                else
                        end=mid-1;
        }

float increment =0.1;

        for(int i=0;i<4;i++)
        {
                while(ans*ans<=number)
                        ans+=increment;

        ans=ans-increment;
        increment=increment/10;
        }


	printf("The square root is: %.4f\n",ans);

	return 0;
}
