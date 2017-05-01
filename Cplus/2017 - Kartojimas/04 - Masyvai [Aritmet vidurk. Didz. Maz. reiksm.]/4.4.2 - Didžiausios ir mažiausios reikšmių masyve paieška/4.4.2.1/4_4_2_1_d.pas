program Atostogu_keliones;
  const  duom = 'Duomenys.txt';
  const  rez = 'Rezultatai.txt';
  type Masyvas1 = array[1..100] of integer;
  type Masyvas2 = array[1..100] of real;
//-------------------------------------------------
function Kaina(s, v, k : integer; sk1, vk1, p1 : real) : real;
   var ss : real;
begin
   ss := 0;
   if (s + v >= k)
   then ss := (s * sk1 + v * vk1) * (100 - p1) * 0.01
   else ss := s * sk1 + v * vk1;
   Kaina := ss;
end;
//-------------------------------------------------
procedure Skaitymas(var s, v, k, n : integer; var SK, VK : Masyvas2; var P : masyvas1; var KK : Masyvas2);
   var             i : integer;
                  fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, s, v);
  ReadLn (fd, k);
  ReadLn (fd, n);
  for i := 1 to n do
     begin
        ReadLn (fd, SK[i], VK[i], P[i]);
        KK[i] := Kaina(s, v, k, SK[i], VK[i], P[i]);
     end;
  Close (fd);
end;
//-------------------------------------------------
function Pigiausia(X :Masyvas2; n : integer) : integer;
   var m, i : integer;
begin
   m := 1;
   for i := 1 to n do
     if X[i] <= X[m] then m := i;
   Pigiausia := m;
end;
//-------------------------------------------------
procedure Rasymas(KK : Masyvas2; n : integer);
   var fr : text; i : integer;
begin
  Assign (fr, rez);
  Rewrite (fr);
  for i := 1 to n do
  WriteLn (fr, i, ' ', KK[i]:0:2);
  WriteLn (fr, Pigiausia(KK, n));
  Close (fr);
end;
//-------------------------------------------------
   var             P : Masyvas1;
          SK, VK, KK : Masyvas2;
       s, v, k, n, m : integer;
begin
  Skaitymas(s, v, k, n, SK, VK, P, KK);
  Rasymas(KK, n);
end.
