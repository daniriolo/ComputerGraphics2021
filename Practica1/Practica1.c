/* Serna Gonzalez Daniel*/
#include <stdio.h>
#include <math.h>
/*  Program that receive as input two coordinates (x1,y1) y (x2,y2)
	and gives as an output an image with the line
 */
int abs(int n){ //Absolute Value Function
	return (n>0)? n:(n*(-1));
}

int max(int a,int b){ //Maximum Value Function
	return (a>b)? a : b;
}
int min(int a,int b){ //Minimum Value Function
	return (a<b)? a : b;
}

void SetPixel(int x,int y){ //Function that prints the coordinates 
	printf("[%d][%d] \n",x,y);
}
 
int main (){ //Main Function
	int x1,x2,y1,y2;
	printf("X1? :\n");
  	scanf("%d",&x1);
	printf("Y1? :\n");
	scanf("%d",&y1);
  	printf("X2? :\n");
  	scanf("%d",&x2);
  	printf("Y2? :\n");
  	scanf("%d",&y2);
  	printf("p1(%d,%d)\n",x1,y1);
  	printf("p2(%d,%d)\n",x2,y2);
	//The calculation of the deltas
  	int dx= x2-x1;
  	int dy=y2-y1;
  	
  	if(dx==0){ //Vertical Line
  		dy=abs(dy);
  		int y=max(y1,y2);
  		while(dy>0){
  			SetPixel(x1,y--);
			--dy;	
		}
	}else if(dy==0){ //Horizontal Line
		dx=abs(dx);
		int x=max(x1,x2);
		while(dx>0){
			SetPixel(x--,y1);
			--dx;
		}
	}else{
		float m = dy/dx; //Slope
		// Y incercept
		float b= y1- m *x1;
		if(abs(m)>1){//Steep
			dy=abs(dy);
			int y=max(y1,y2);
			while(dy>0){
				int x= round((y-b)/m);
				SetPixel(x,y--);
				--dy;
			}
		}else{ //Shallow
			dx=abs(dx);
			int x =max(x1,x2);
			while(dx>0){
				int y=m*x+b;
				SetPixel(x--,y);
				--dx;
			}
		} 
	}
  	
	return 0;
}
