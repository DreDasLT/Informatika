program �aidimas;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
   var           n, i : integer;          // korteli� skai�ius
                 p, a : integer;         // pirma ir antra kortel�
                 smax : integer;         // did�iausia suma
           pmax, amax : integer;         // did�iausios sumos d�menys
               fd, fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  Readln (fd, n);
  Read (fd, p, a);
  smax := p + a;
  pmax := p; amax := a;
  for i := 2 to n div 2 do
    begin
       Read (fd, p, a);
       if p + a > smax then
         begin
            smax := p + a;
            pmax := p;
            amax := a;
         end;
    end;
  Close (fd);
  Assign (fr, rez);
  Rewrite (fr);
  WriteLn (fr, smax, ' ', pmax, ' ', amax);
  if pmax = amax then WriteLn (fr, '1 2')
     else if (pmax > amax) then WriteLn (fr, 1)
            else WriteLn (fr, 2);
  Close (fr);
end.

