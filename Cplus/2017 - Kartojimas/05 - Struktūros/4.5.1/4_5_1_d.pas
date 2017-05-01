program Studentai;
  const  duom = 'Duomenys1.txt';
  const  rez = 'Rezultatai1.txt';
  type Marsrutai = record
                      pav : string[20];
                   vi, mi : integer;
                   va, ma : integer;
                        t : longint;
                   end;
      Masyvas1 = array[1..100] of Marsrutai;
//-------------------------------------------------
function Trukme(vi, mi, va, ma : integer) : longint;
begin
    if (vi * 60 + mi <= va * 60 + ma)
      then Trukme := va * 60 + ma - vi * 60 - mi
      else Trukme := 24 * 60 - vi * 60 - mi + va * 60 + ma;
end;
//-------------------------------------------------
procedure Skaitymas (var M : Masyvas1; var n : integer; var s : longint);
   var             i : integer;
                  fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  s := 0;
  ReadLn (fd, n);
  for i := 1 to n do
    begin
       ReadLn (fd, M[i].pav, M[i].vi, M[i].mi, M[i].va, M[i].ma);
       M[i].t := Trukme(M[i].vi, M[i].mi, M[i].va, M[i].ma);
       s := s + M[i].t;
    end;
  Close (fd);
end;
//-------------------------------------------------
function Visa(M : Masyvas1; n : integer) : longint;
   var v : longint;i : integer;
begin
   v := 0;
  for i := 1 to n - 1 do
    v := v + Trukme(M[i].va, M[i].ma, M[i + 1].vi, M[i + 1].mi);
  Visa := v;
end;
//-------------------------------------------------
procedure Rasymas(M : Masyvas1; n : integer; v, t : longint);
   var fr : text; i : integer;
begin
  Assign (fr, rez);
  Rewrite (fr);
  for i := 1 to n do
  if M[i].t mod 60 < 10
  then WriteLn (fr, M[i].pav, ' ', M[i].t div 60, ' 0', M[i].t mod 60)
  else WriteLn (fr, M[i].pav, ' ', M[i].t div 60, ' ', M[i].t mod 60);
  WriteLn (fr, (t + v) div 60, ' ', (t + v) mod 60);
  Close (fr);
end;
//-------------------------------------------------
   var       n : integer;
             M : Masyvas1;
          v, s : longint;
begin
  Skaitymas(M, n, s);
  v := Visa(M, n);
  Rasymas(M, n, v, s);
end.
