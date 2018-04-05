/**
 *	COP290
 *	ed.cpp
 *	Purpose: Design and implement a software package for Engineering drawing
 *	@author Ayush Verma [2016cs10374] && Pradyumna Meena [2016cs10375]
 *	@version 1.0 4/03/2018
 */
#include <iostream>
#include <GL/glut.h>
using namespace std;

int cx=0, cy=0, cz=0;
int cn;
/**
 * Structure of Quads which contain face of quadrant  
 */
struct Quads{
	int x1,y1,z1, x2,y2,z2, x3,y3,z3, x4,y4,z4;
	float r,g,b;
	int state;
	int total;
}; 
/**
 * Structure of Coordinate of a point in 3 dimensions  
 */
struct Coordinate{
	int x1,y1,z1;
	int t;
};
Quads Q[100];
Quads QT[100];
Quads Q1[100];
Quads Q2[100]; 
Quads Q3[100];
/**
 * addQuads method is for making a new Quad when called upon.
 */
void addQuads(){
	Q[0].state++; if(Q[0].state>4){ Q[0].state =1;}
	int st = Q[0].state;  
	if(st==1){ Q[0].total++; cn=Q[0].total;}
	if(st==1){ Q[cn].x1=cx; Q[cn].y1=cy; Q[cn].z1=cz;}
	if(st==1 || st==2){ Q[cn].x2=cx; Q[cn].y2=cy; Q[cn].z2=cz;}
	if(st==1||st==2||st==3){ Q[cn].x3=cx; Q[cn].y3=cy; Q[cn].z3=cz;}
	if(st==1||st==2||st==3||st==4){ Q[cn].x4=cx; Q[cn].y4=cy; Q[cn].z4=cz;}
}
/**
 * drawQuads method is for displaying User made view in Display menu.
 */
void drawQuads(){
	int i;
	for (i=1;i<Q[0].total+1;i++){
		glBegin(GL_QUADS);
		glColor3f(Q[i].r,Q[i].g,Q[i].b);
		glVertex3f(Q[i].x1,Q[i].y1,Q[i].z1);
		glVertex3f(Q[i].x2,Q[i].y2,Q[i].z2);
		glVertex3f(Q[i].x3,Q[i].y3,Q[i].z3);
		glVertex3f(Q[i].x4,Q[i].y4,Q[i].z4);
		glEnd();
	}
}
/**
 * front2Dview method is for displaying User made front view in Display menu.
 */
void front2Dview(){
	Q1[0].state++; if(Q1[0].state>4){ Q1[0].state =1;}
	int st = Q1[10].state;  
	if(st==1){ Q1[0].total++; cn=Q1[0].total;}
	if(st==1){ Q1[cn].x1=cx; Q1[cn].y1=cy; Q1[cn].z1=0;}
	if(st==1 || st==2){ Q1[cn].x2=cx; Q1[cn].y2=cy; Q1[cn].z2=0;}
	if(st==1||st==2||st==3){ Q1[cn].x3=cx; Q1[cn].y3=cy; Q1[cn].z3=0;}
	if(st==1||st==2||st==3||st==4){ Q1[cn].x4=cx; Q1[cn].y4=cy; Q1[cn].z4=0;}
}
/**
 * drawfront2D method is for making User made front view in front plane of Display menu.
 */
void drawfront2D(){
	int i;
	for (i=1;i<Q1[0].total+1;i++){
		glBegin(GL_QUADS);
		glColor3f(Q1[i].r,Q1[i].g,Q1[i].b);
		glVertex3f(Q1[i].x1,Q1[i].y1,Q1[i].z1);
		glVertex3f(Q1[i].x2,Q1[i].y2,Q1[i].z2);
		glVertex3f(Q1[i].x3,Q1[i].y3,Q1[i].z3);
		glVertex3f(Q1[i].x4,Q1[i].y4,Q1[i].z4);
		glEnd();
	}
}
/**
 * side2Dview method is for displaying User made side view in Display menu.
 */
void side2Dview(){
	Q2[0].state++; if(Q2[0].state>4){ Q2[0].state =1;}
	int st = Q2[0].state;  
	if(st==1){ Q2[0].total++; cn=Q2[0].total;}
	if(st==1){ Q2[cn].x1=19; Q2[cn].y1=cy; Q2[cn].z1=cz;}
	if(st==1 || st==2){ Q2[cn].x2=19; Q2[cn].y2=cy; Q2[cn].z2=cz;}
	if(st==1||st==2||st==3){ Q2[cn].x3=19; Q2[cn].y3=cy; Q2[cn].z3=cz;}
	if(st==1||st==2||st==3||st==4){ Q2[cn].x4=19; Q2[cn].y4=cy; Q2[cn].z4=cz;}
}
/**
 * drawside2D method is for making User made front view in side plane of Display menu.
 */
void drawside2D(){
	int i;
	for (i=1;i<Q2[0].total+1;i++){
		glBegin(GL_QUADS);
		glColor3f(Q2[i].r,Q2[i].g,Q2[i].b);
		glVertex3f(Q2[i].x1,Q2[i].y1,Q2[i].z1);
		glVertex3f(Q2[i].x2,Q2[i].y2,Q2[i].z2);
		glVertex3f(Q2[i].x3,Q2[i].y3,Q2[i].z3);
		glVertex3f(Q2[i].x4,Q2[i].y4,Q2[i].z4);
		glEnd();
	}
}
/**
 * top2Dview method is for displaying User made top view in Display menu.
 */
void top2Dview(){
	Q3[0].state++; if(Q3[0].state>4){ Q3[0].state =1;}
	int st = Q3[0].state;  
	if(st==1){ Q3[0].total++; cn=Q3[0].total;}
	if(st==1){ Q3[cn].x1=cx; Q3[cn].y1=0; Q3[cn].z1=cz;}
	if(st==1 || st==2){ Q3[cn].x2=cx; Q3[cn].y2=0; Q3[cn].z2=cz;}
	if(st==1||st==2||st==3){ Q3[cn].x3=cx; Q3[cn].y3=0; Q3[cn].z3=cz;}
	if(st==1||st==2||st==3||st==4){ Q3[cn].x4=cx; Q3[cn].y4=0; Q3[cn].z4=cz;}
}
/**
 * drawtop2D method is for making User made front view in top plane of Display menu.
 */
void drawtop2D(){
	int i;
	for (i=1;i<Q3[0].total+1;i++){
		glBegin(GL_QUADS);
		glColor3f(Q3[i].r,Q3[i].g,Q3[i].b);
		glVertex3f(Q3[i].x1,Q3[i].y1,Q3[i].z1);
		glVertex3f(Q3[i].x2,Q3[i].y2,Q3[i].z2);
		glVertex3f(Q3[i].x3,Q3[i].y3,Q3[i].z3);
		glVertex3f(Q3[i].x4,Q3[i].y4,Q3[i].z4);
		glEnd();
	}
}
/**
 * frontview method is for defining front view from a 3D image made by user.
 */
void frontview(){
	
	int j = 0;	
	int ttotal=Q[0].total;
	for(int i = 1;i<(ttotal+1);i++){
		QT[j].x1=Q[i].x1;
		QT[j].x2=Q[i].x2;
		QT[j].x3=Q[i].x3;
		QT[j].x4=Q[i].x4;
		QT[j].y1=Q[i].y1;
		QT[j].y2=Q[i].y2;
		QT[j].y3=Q[i].y3;
		QT[j].y4=Q[i].y4;
		QT[j].z1=0;
		QT[j].z2=0;
		QT[j].z3=0;
		QT[j].z4=0;
		j++;
	
	}
}
/**
 * sideview method is for defining side view from a 3D image made by user.
 */
void sideview(){
	
	int j = 0;	
	int ttotal=Q[0].total;
	for(int i = 1;i<(ttotal+1);i++){
		QT[j].x1=19;
		QT[j].x2=19;
		QT[j].x3=19;
		QT[j].x4=19;
		QT[j].y1=Q[i].y1;
		QT[j].y2=Q[i].y2;
		QT[j].y3=Q[i].y3;
		QT[j].y4=Q[i].y4;
		QT[j].z1=Q[i].z1;
		QT[j].z2=Q[i].z2;
		QT[j].z3=Q[i].z3;
		QT[j].z4=Q[i].z3;
		j++;
	
	}
}
/**
 * topview method is for defining top view from a 3D image made by user.
 */
void topview(){
	
	int j = 0;	
	int ttotal=Q[0].total;
	for(int i = 1;i<(ttotal+1);i++){
		QT[j].x1=Q[i].x1;
		QT[j].x2=Q[i].x2;
		QT[j].x3=Q[i].x3;
		QT[j].x4=Q[i].x4;
		QT[j].y1=0;
		QT[j].y2=0;
		QT[j].y3=0;
		QT[j].y4=0;
		QT[j].z1=Q[i].z1;
		QT[j].z2=Q[i].z2;
		QT[j].z3=Q[i].z3;
		QT[j].z4=Q[i].z4;
		j++;
	
	}
}
/**
 * drawfront method is for making front view from a 3D image made by user in display menu.
 */
void drawfront(){
	int i;
	for (i=0;i<Q[0].total;i++){
		glBegin(GL_QUADS);
		glColor3f(0,0,1);
		glVertex3f(QT[i].x1,QT[i].y1,QT[i].z1);
		glVertex3f(QT[i].x2,QT[i].y2,QT[i].z2);
		glVertex3f(QT[i].x3,QT[i].y3,QT[i].z3);
		glVertex3f(QT[i].x4,QT[i].y4,QT[i].z4);
		glEnd();
	}
}
/**
 * drawside method is for making side view from a 3D image made by user in display menu.
 */
void drawside(){
	int i;
	for (i=0;i<Q[0].total;i++){
		glBegin(GL_QUADS);
		glColor3f(0,1,0);
		glVertex3f(QT[i].x1,QT[i].y1,QT[i].z1);
		glVertex3f(QT[i].x2,QT[i].y2,QT[i].z2);
		glVertex3f(QT[i].x3,QT[i].y3,QT[i].z3);
		glVertex3f(QT[i].x4,QT[i].y4,QT[i].z4);
		glEnd();
	}
}
/**
 * drawtop method is for making top view from a 3D image made by user in display menu.
 */
void drawtop(){
	int i;
	for (i=0;i<Q[0].total;i++){
		glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex3f(QT[i].x1,QT[i].y1,QT[i].z1);
		glVertex3f(QT[i].x2,QT[i].y2,QT[i].z2);
		glVertex3f(QT[i].x3,QT[i].y3,QT[i].z3);
		glVertex3f(QT[i].x4,QT[i].y4,QT[i].z4);
		glEnd();
	}
}
Coordinate C[400];
/**
 * points method is for extracting all 3D points from front side and top view.
 */
void points(){
	int i;
	int k;
	int l;
	int za;
	int xa;
	int ya;
	for(i=1;i<Q1[0].total+1;i++){
		xa = Q1[i].x1;
		ya = Q1[i].y1;
		for(k=1;k<Q2[0].total+1;k++){
			if(Q2[k].y1==ya){
				za = Q2[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
				 	
			}
			if(Q2[k].y2==ya){
				za = Q2[k].z2;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y3==ya){
				za = Q1[k].z3;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y4==ya){
				za = Q1[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
		}
		xa = Q1[i].x2;
		ya = Q1[i].y2;
		for(k=1;k<Q2[0].total+1;k++){
			if(Q2[k].y1==ya){
				za = Q2[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
				 	
			}
			if(Q2[k].y2==ya){
				za = Q2[k].z2;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y3==ya){
				za = Q1[k].z3;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y4==ya){
				za = Q1[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
		}
		//
		xa = Q1[i].x3;
		ya = Q1[i].y3;
		for(k=1;k<Q2[0].total+1;k++){
			if(Q2[k].y1==ya){
				za = Q2[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
				 	
			}
			if(Q2[k].y2==ya){
				za = Q2[k].z2;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y3==ya){
				za = Q1[k].z3;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y4==ya){
				za = Q1[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
		}
//
		xa = Q1[i].x3;
		ya = Q1[i].y3;
		for(k=1;k<Q2[0].total+1;k++){
			if(Q2[k].y1==ya){
				za = Q2[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
				 	
			}
			if(Q2[k].y2==ya){
				za = Q2[k].z2;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y3==ya){
				za = Q1[k].z3;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y4==ya){
				za = Q1[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
		}		
		xa = Q1[i].x4;
		ya = Q1[i].y4;
		for(k=1;k<Q2[0].total+1;k++){
			if(Q2[k].y1==ya){
				za = Q2[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
				 	
			}
			if(Q2[k].y2==ya){
				za = Q2[k].z2;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y3==ya){
				za = Q1[k].z3;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
			if(Q2[k].y4==ya){
				za = Q1[k].z1;
				for(l=1;Q3[0].total+1;k++){
					if(Q3[l].x1==xa && Q3[l].z1==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x2==xa && Q3[l].z2==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x3==xa && Q3[l].z3==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}
					if(Q3[l].x4==xa && Q3[l].z4==za){
						C[0].t++;
						l= C[0].t;
						C[l].x1=xa;
						C[l].y1=ya;
						C[l].z1=za;			
					}				
				}
			}
		}
 	
	}
	//C = removeduplicate(C);
	//return C

}
/**
 * removeduplicate method takes Array of Quad and is for making set of all 3d points exteracted in points method.
 */
void removeduplicate(Quads a){

}
/**
 * drawgraph method takes Array of coordinates and is for making graph of a 3d object.
 */
void drawgraph(Coordinate x){}
/**
 * threedtwod method is for making set of all 3d object from three 2 dimensional views.
 */
void threedtwod(){
	
}
/**
 * theCube method is for making small cube in display which work as pointer.
 */
void theCube(){
	glPushMatrix();  
	glColor3f(1,1,1);
	glTranslatef(cx,cy,cz);
	glutSolidCube(0.4);
}
/**
 * drawGrid method draw grid in display menu.
 */
void drawGrid(){
  int i;
  for(i=0;i<40;i++){
    glPushMatrix();
    if(i<20){glTranslatef(0,0,i);}
    if(i>=20){ glTranslatef(i-20,0,0); glRotatef(-90,0,1,0);}
    glBegin(GL_LINES);
    glColor3f(1,1,1); glLineWidth(1);
    
    glVertex3f(0,-0.1,0); glVertex3f(19,-0.1,0);
    
    glEnd();
    glPopMatrix();
  }
}

/**
 * display method is for displaying Grid cube , 3D and 2d objects using openGL.
 */
void display(){
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(-13,0,-45);
  glRotatef(40,1,1,0); //to rotate the cube so it does not seem to be square.
  
  drawGrid();
  drawQuads();
  drawfront2D();
  drawside2D();
  drawtop2D();
  drawfront();
  drawside();
  drawtop();
  theCube();
  glutSwapBuffers();
}
/**
 * init method to initialize display .
 */
void init(){
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(35,1.0f,0.1f,1000);
  glMatrixMode(GL_MODELVIEW);
  glEnable(GL_DEPTH_TEST);
  glClearColor(0.2,0.2,0.2,1);
}
/**
 * Keyboard method takes input from user through keyboard for various task.  
 */
void keyboard(unsigned char key,int x, int y){
	if (key=='w'){cz-=1;} if(key=='s'){cz+=1;}
	if (key=='a'){cx-=1;} if(key=='d'){cx+=1;}
	if (key=='q'){cy-=1;} if(key=='z'){cy+=1;}
	if (key==32){ addQuads();}
	if (key=='o') { front2Dview();}
	if (key=='l') { side2Dview();}
	if (key=='m') { top2Dview();}
	if (key=='r') {Q[cn].r=1;Q[cn].g=0;Q[cn].b=0;}
	if (key=='g') {Q[cn].r=0;Q[cn].g=1;Q[cn].b=0;}
	if (key=='b') {Q[cn].r=0;Q[cn].g=0;Q[cn].b=1;}
	if (key=='y') {Q[cn].r=1;Q[cn].g=1;Q[cn].b=0;}
	if (key=='f') { frontview();}
	if (key=='x') { sideview();}
	if (key=='t') { topview();}
    	
	glutPostRedisplay();
}
/**
 * The main function will be use for calling instantiating classes and using their functions
 * and various other functions.  
 */
int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE);
  glutInitWindowSize(800,600);
  glutCreateWindow("cad");
  glutDisplayFunc(display);
  glutKeyboardFunc(keyboard);
  init();
 
  glutMainLoop();

  return 0;
}
