import java.util.*;


public class Main{ 
	static int b=5;
	static int value[][]= {{0,0,0,0,0},
	{1,11,0,2,20},
	{2,12,5,10,21},
	{3,13,10,30,22},
			{4,14,15,32,23},
			{5,15,20,40,24}};//投资k项目x万元的收益
	static int F[][]=new int[6][5];
	static int num[][]=new int[6][5];//备忘录储存各阶段的解
public static void main(String[] args) {
	maxValue();//求最大收益，并标记
	trackPrint();}//追踪各阶段的解
public static void maxValue() {
for(int x=1;x<=5;x++) {
for(int k=1;k<=4;k++) {
for(int i=x;i>=0;i--)
if(F[x][k]<value[i][k]+F[x-i][k-1]) {
F[x][k]=value[i][k]+F[x-i][k-1];//更新最大收益
num[x][k]=i;//标记
}
}}}
public static void trackPrint() {

for(int i=4;i>=1;i--) {
System.out.println(i+"号项目投资"+num[b][i]+"万元");
b-=num[b][i];}

}}