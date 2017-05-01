program Islaidos;
  const  duom = 'Duomenys.txt';
  const  rez = 'Rezultatai.txt';
  type Degaline = record
                      pav : string[15];
                     b, d : real;
                   end;
      Masyvas1 = array[1..100] of Degaline;
//-------------------------------------------------
function Kaina(x, y : real) : real;
begin
   Kaina := (x / 100) * y;
end;
//-------------------------------------------------
procedure Skaitymas (var D : Masyvas1; var n : integer);
   var             i : integer;
           bb, dd, m : real;
              kb, kd : real;
                  fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, bb, dd, m, n);
  for i := 1 to n do
    begin
       ReadLn (fd, D[i].pav, kb, kd);
       D[i].b := Kaina(m, bb) * kb;
       D[i].d := Kaina(m, dd) * kd;
    end;
  Close (fd);
end;
//-------------------------------------------------
procedure Rasymas(D : Masyvas1; n : integer);
   var fr : text; i : integer;
begin
  Assign (fr, rez);
  Rewrite (fr);
  for i := 1 to n do
    WriteLn (fr, D[i].pav, ' ', D[i].b:0:2, ' ', D[i].d:0:2);
  Close (fr);
end;
//-------------------------------------------------
   var       n : integer;
             D : Masyvas1;
begin
  Skaitymas(D, n);
  Rasymas(D, n);
end.
