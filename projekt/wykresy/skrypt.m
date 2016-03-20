clear all;

hold on;
grid on;
grid minor;

A=fopen('czasy_miliard.txt','r');
czasy_miliard = fscanf(A,'%f');
B=fopen('czasy_milion.txt','r');
czasy_milion = fscanf(B,'%f');
C=fopen('czasy_stotysiecy.txt','r');
czasy_stotysiecy = fscanf(C,'%f');

for i=1:50
	x_miliard(i,1) = 1000000000;
x_milion(i,1)  = 1000000;
x_stotysiecy(i,1) = 100000;
end

plot(x_stotysiecy,czasy_stotysiecy,'bx');
plot(x_milion,czasy_milion,'bx');
plot(x_miliard,czasy_miliard,'bx');


