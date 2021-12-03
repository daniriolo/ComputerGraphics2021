/* Serna Gonzalez Daniel 
	Its not complete , i just wrote the algorithms to render , but i need to bring the algorithms to practical.
*/
#define N 1000
#include <stdio.h>
#include <stdlib.h>

typedef struct RGB{ //This helpes me to create a matrix with 3 data in one position of a matrix
	int red;
	int green;
	int blue;
}RGB;

int min (int a, int b){                                                         //Function to obtain MIN value for int 
    return (a<b)? a:b;
}

int max (int a, int b){                                                         //Function to obtain MAX value for int
    return (a>b)? a:b;
}


void drawImg(RGB matrix[N][N]){  //Function to write the matrix in a ppm file
	int i,j;
	FILE *obj = fopen("model.ppm","wb");
	(void) fprintf(fobj,"P3\n%d %d\n255\n",N,N);
	for(i=N-1;i>=0;i--){
		for(j=0;j<N;j++){
			fprintf(fobj, "%d %d %d\n", matrix[j][i].red, matrix[j][i].green, matrix[j][i].blue);	
		}
	}	
}

void SetPixel(int x,int y){
    matrix[x][y].red = 255;
    matrix[x][y].green = 255;
    matrix[x][y].blue = 255;
}

void NaiveApproach (int x1, int y1, int x2, int y2){
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
}

void DDA (int x1, int y1, int x2, int y2){

    if(abs(y2-y1) == abs(x2-x1)){                                               //Case when its equal
        SetPixel(x1,y1);
    }

    if(abs(y2-y1) < abs(x2-x1)){
        int nX = x1;
        int nY = y1; 
        for(; nX <= x2; nX++){
            nY += ((y2-y1)/(x2-x1));                                           //Calculate the Y for each X using the past point
            int Y = (int)nY;                                                   //and the new one was the slope 
	    SetPixel(nX,Y);
        }
    }else{
        int nX = x1;
        int nY = y1; 
        for(; nY <= y2; nY++){
            nX += ((x2-x1)/(y2-y1));                                           //Calculate the X for each Y using the past point
            int X = (int)nX;                                                   //and the new one was the slope
	    SetPixel(X,nY);
        }
    }  
    
return;
} 

void Bresenham(int x1, int y1, int x2, int y2){                                

    int slope = 2 * (y2-y1);                                                //Calculate the possible update of slope to the E
    int nslope = slope - (x2 - x1);                                         //Calculate the possible update of slope to the NE
    int nX = x1; 
    int nY = y1;

    for(; nX <= x2; nX++){
	SetPixel(nX,nY);
        nslope += slope;                                                    //Sum of both possible updates
        if(nslope >= 0){                                                    //Check that it's greater than 0 
            nY++;                                                              //that means that we move NE (it's Bresenham observation)
            nslope -= 2 * (x2 - x1);                                    
        }
    }

return;
}


int main(){
	
}
