f(x) = 904.8*exp(0.0089*x)

set terminal png size 800, 700
set title "metodo de euler"
set xlabel "tempo (dias)"
set ylabel "vol. de celulas (mm^3)"
set output "euler"
plot f(x) title "analitic0", "euler.txt" title "computado"

set title "metodo de runge-kutta de ordem 2"
set output "rk2"
plot f(x) title "analitico", "rk2.txt" title "computado"

set title "metodo de runge-kutta de ordem 4"
set output "rk4"
plot f(x) title "analitico", "rk4.txt" title "computado"


set yrange [0:180]
set title "erro nos distintos metodos"
set output "erro_todos"
set xlabel "h"
set ylabel "erro (mm^3)"
plot "erro_e_rk2_rk4.txt" u 1:2 title "euler", "erro_e_rk2_rk4.txt" u 1:3 title "rk2", "erro_e_rk2_rk4.txt" u 1:4 title "rk4"

unset yrange
set title "erro nos metodos rk2 e rk4"
set output "erro_rk2_rk4"
plot "erro_e_rk2_rk4.txt" u 1:3 title "rk2", "erro_e_rk2_rk4.txt" u 1:4 title "rk4"

set title "erro no metodo rk4"
set output "erro_rk4"
plot "erro_e_rk2_rk4.txt" u 1:4 title "rk4"

pause -1
