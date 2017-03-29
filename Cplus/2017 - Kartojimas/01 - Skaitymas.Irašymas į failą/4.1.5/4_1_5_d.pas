program Kalba;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
   var      n : integer;          // daþniausiai vartojamu þodþiø skaièius
            d : integer;          // po keliø dienø iðvyksta
            z : integer;          // pirmà dienà iðmoktø þodþiø skaièius
            k : integer;          // keliais þodþiais daugiau iðmokdavo kiekvienà kità dienà
                                  // negu prieð tai buvusià
           dt : integer;          // per kiek dienø iðmoks n þodþiø
            s : integer;          // iðmoktø þodþiø suma
       fd, fr : text;
begin
  s := 0; dt := 0;
  Assign (fd, duom);
  Reset (fd);
  Readln (fd, n, d, z, k);
  Close (fd);
  while s < n do
    begin
       s  := s + z;
       dt := dt + 1;
       z  := z+ k;
    end;
  Assign (fr, rez);
  Rewrite (fr);
  WriteLn (fr, dt);
  if dt <= d then WriteLn (fr, 'TAIP')
     else WriteLn (fr, 'NE');
  Close (fr);
end.

