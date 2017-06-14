program EgzaminoUzduotis;
const
  RezF  = 'U2rez.txt';  { rezultatø failo pavadinimas }
  
type skaiciaiMas = array[1..1000] of integer;

//***********************

procedure GaukSkaicius(var visi: skaiciaiMas; var dydis:integer); { visada kuria skirtingus skaièius }
var i, j, sk, m : integer;
 nera : boolean;
begin
 repeat
    nera:=true;
    sk:=random(9999)+1; { funkcija random gràþina skaièiø nuo 0 iki 9999 }
    i := 0;
     while (i < dydis) and (nera) do
        begin
            i:=i+1;
            if (visi[i] = sk) then nera := false;
        end;
 until nera;
 dydis := dydis + 1;
 visi[dydis] := sk;
end;

//***********************

function Apversk():skaiciaiMas;

begin

end;

//***********************

procedure RasykRezultata();

begin

end;

//***********************

var       i, kiek, num : integer;
  duomenys, rezultatai : skaiciaiMas;
begin
 randomize; { procedûra, kuri inicijuoja atsitiktiniø skaièiø generatoriø }
 kiek := 0;
 for i := 1 to random(900)+10 do
    GaukSkaicius(duomenys, kiek);
    
 rezultatai := Apversk();
 RasykRezultata();
end.
