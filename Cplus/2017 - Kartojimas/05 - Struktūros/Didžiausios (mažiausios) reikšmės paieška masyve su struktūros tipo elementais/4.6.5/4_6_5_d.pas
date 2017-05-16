program Populiariausios_kalbos;
  const  duom = 'Duomenys.txt';
  const  rez = 'Rezultatai.txt';
  type Kalba = record
                      pav : string[25];
                        p : integer;
                   end;
      Masyvas1 = array[1..100] of Kalba;
//-------------------------------------------------
function Pokytis(x, y : integer) : integer;
begin
   Pokytis := x - y;
end;
//-------------------------------------------------
procedure Skaitymas (var K : Masyvas1; var n : integer);
   var             i : integer;
              n1, n2 : integer;
                  fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, n);
  for i := 1 to n do
    begin
       ReadLn (fd, K[i].pav, n1, n2);
       K[i].p := Pokytis(n2, n1);
    end;
  Close (fd);
end;
//-------------------------------------------------
function Daugiausia(K : Masyvas1; n : integer) : integer;
  var m, i : integer;
begin
   m := 1;
   for i := 1 to n do
     if K[i].p > K[m].p then m := i;
   Daugiausia := m;
   end;
//-------------------------------------------------
function Maziausia(K : Masyvas1; n : integer) : integer;
  var m, i : integer;
begin
   m := 1;
   for i := 1 to n do
     if K[i].p < K[m].p then m := i;
   Maziausia := m;
   end;
//-------------------------------------------------
procedure Rasymas(K : Masyvas1; n : integer);
   var fr : text; i, m : integer;
begin
  Assign (fr, rez);
  Rewrite (fr);
  m := Daugiausia (K, n);
  WriteLn (fr, K[m].p);
  for i := 1 to n do
    if K[i].p = K[m].p then WriteLn (fr, K[i].pav);
  m := Maziausia (K, n);
  WriteLn (fr, abs(K[m].p));
  for i := 1 to n do
    if K[i].p = K[m].p then WriteLn (fr, K[i].pav);
  Close (fr);
end;
//-------------------------------------------------
   var       n : integer;
             D : Masyvas1;
begin
  Skaitymas(D, n);
  Rasymas(D, n);
end.
