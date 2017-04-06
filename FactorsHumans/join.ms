.PS
define endBox
{
	B:box $1;
	line from B.sw - (0, 0.05) to B.se - (0, 0.05);
}

# Comença la màgia.
down;
box "Unirse";
L1:line " Estar logeado" ljust;

# Primer apartat.
right;
L1B1:box with .n at L1.end - (1.875, lineht) "Encender la" "aplicaci\('on"
move;
L1B2:box "Buscar" "Fiesta";
move;
L1B3:box "Ir a la" "Fiesta";
move;
L1B4:box "Introducir" "codigo";

# Bucle
up;
for i = 1 to 4 do {
	line at `i'th last box.n;
	line from `i'th last box.sw - (0, 0.05) to `i'th last box.se - (0, 0.05);
}

# Linia general
line from `2'th line .n to `2'th last line .n;

move to L1B3.n;
line invisible " En caso" ljust " de no estar" ljust;

# Numerant les caixes
"0" at `1'th box .se rjust above
"1" at `2'th box .se rjust above
"2" at `3'th box .se rjust above
"3" at `4'th box .se rjust above
"4" at `5'th box .se rjust above

# Ideal
# for i = 1 to 5 do {
# 	sprintf ( "%d", i-1 ) at `i'th box .se rjust above
# }
.PE
