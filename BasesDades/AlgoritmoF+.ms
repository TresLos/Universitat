.ds RED "\X'ps: exec 1 0 0 setrgbcolor'
.ds BLACK "\X'ps: exec 0 0 0 setrgbcolor'

.EQ
delim $%
define a 'alpha'
define b 'beta'
define c 'gamma'
define d 'delta'
define f %{$1 -> $2}%
.EN
.ig tot
Testeixant l'algoritme per calcular $F sup +% si $F = left{ a -> b , a -> c right }%
.TS
delim($%);
c	s	s	s	s	s
c|	c	|c	s	s|	c
c	c	c	c	c	c
n	n	n	n	n	n.
1er bucle
Entrada	Reflexivitat	Aumentativitat	Transitivitat
		$a%	$b%	$c%
$a% \&$-> b%	\*[RED]$a% \&$-> a%\*[BLACK]	$a% \&$-> a b%	$a b% \&$-> b%	$a c% \&$-> b c%	$a% \^$-> b c%
$a% \&$-> c%	\*[RED]$b% \&$-> b%\*[BLACK]	$a% \&$-> a c%	$a b% \&$-> b c%	$a c% \&$-> c%
\*[RED]	$c% \&$-> c%	$a b% \&$-> a b%	$b c% \&$-> b c%
		$a c% \&$-> a c%\*[BLACK]
=
.T&
c	s	s	s	s	s
n	n	n	n	n	n.
Segon bucle
		$a c% \&$-> a b c%	$a b c% \&$-> b c%		$a% \&$-> a b c%
		$a b% \&$-> a b c%
		\*[RED]$a b c% \&$-> a b c%\*[BLACK]
.TE
..
.tot

Testeixant l'algoritme per calcular $F sup +% si $F = left{ a -> b c right }%
.TS
delim($%);
c|	c	|c	s	s|	c
c	s	s	s	s	s
c	c	c	c	c	c
n	n	n	n	n	n.
Entrada	Reflexivitat	Aumentativitat	Transitivitat
1er bucle
		$a%	$b%	$c%
$a% \&$-> b c%	$b c% \&$-> b%	$a% \&$-> a b c%	$a b% \&$-> b c%	$a c% \&$-> b c%	$a% \&$-> b%
	$b c% \&$-> c%	$a b c% \&$-> a b%	\*[RED]$a b% \&$-> a b%	$a c% \&$-> a c%\*[BLACK]	$a% \&$-> c%
	\*[RED]$b c% \&$-> b c%\*[BLACK]	$a b c% \&$-> a c%			$a% \&$-> a b%
	\*[RED]$a% \&$-> a%	$a b c% \&$-> a b c%\*[BLACK]			$a% \&$-> a c%
					$a% \&$-> a b c%
					$a b c% \&$-> b c%
					$a b% \&$-> b%
					$a b% \&$-> c%
					$a c% \&$-> b%
					$a c% \&$-> c%
_
.T&
c	s	s	s	s	s
n	n	n	n	n	n.
2 bucle
	$a b c% \&$-> a%	$a b% \&$-> a b c%	$a b% \&$-> a b c%
	$a b c% \&$-> b%	$a c% \&$-> a b c%
	$a b c% \&$-> c%
	$a b c% \&$-> a b%
	$a b c% \&$-> a c%
	$a b c% \&$-> b c%
	$a b% \&$-> a%
	$a b% \&$-> b%
	$a c% \&$-> a%
	$a c% \&$-> c%
	\*[RED]$a b c% \&$-> a b c%
.TE

.ig tot
Testeixant l'algoritme per calcular $F sup +% si $F = left{ a -> b, bc -> d right }%
.TS
delim($%);
c	s	s	s	s	s	s
c|	c	|c	s	s	s|	c
c	c	c	c	c	c	c
n	n	n	n	n	n	n.
1er bucle
Entrada	Reflexivitat	Aumentativitat	Transitivitat
		$a%	$b%	$c%	$d%
$a% \&$-> b%
.TE
..
.tot
