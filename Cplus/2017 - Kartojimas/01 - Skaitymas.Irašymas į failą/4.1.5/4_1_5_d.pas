program Kalba;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
   var      n : integer;          // da�niausiai vartojamu �od�i� skai�ius
            d : integer;          // po keli� dien� i�vyksta
            z : integer;          // pirm� dien� i�mokt� �od�i� skai�ius
            k : integer;          // keliais �od�iais daugiau i�mokdavo kiekvien� kit� dien�
                                  // negu prie� tai buvusi�
           dt : integer;          // per kiek dien� i�moks n �od�i�
            s : integer;          // i�mokt� �od�i� suma
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

