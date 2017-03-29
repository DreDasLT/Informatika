program Traukinys;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
   var a, b, c, d : longint;
             v, m : integer;
               fd : text;
               fr : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, a, b, c, d);
  Close (fd);
  v := (a * 60 + b + c * 60 + d) div 60 mod 24;
  m := (a * 60 + b + c * 60 + d) mod 60;
  Assign (fr, rez);
  Rewrite (fr);
  WriteLn (fr, v, ' ', m);
  Close (fr);
end.

