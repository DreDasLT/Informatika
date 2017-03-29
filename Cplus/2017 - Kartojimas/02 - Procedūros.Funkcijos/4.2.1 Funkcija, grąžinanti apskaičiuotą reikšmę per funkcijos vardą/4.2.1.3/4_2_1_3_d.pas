program Patiekalas;
   const  duom = 'Duomenys.txt';
   const  rez = 'Rezultatai.txt';
//-------------------------------------------------
function Procentai (y : integer; x : real) : real;
   begin
      Procentai := x * 100 / y;
   end;
//-------------------------------------------------
   var        n : integer;    // produktø skaièius
        r, b, a : real;       // produkte esantys riebalø, baltymø ir angliavandeniø kiekiai gramais
              p : integer;    // produkto masë gramais
     rr, bb, aa : real;       // bendra sudedamøjø daliø masë gramais
             pp : integer;    // bendra produktø masë gramais
              i : integer;
         fd, fr : text;
begin
  rr := 0; bb := 0; aa := 0; pp := 0;
  Assign (fd, duom);
  Reset (fd);
  Readln (fd, n);
  for i := 1 to n do
     begin
        ReadLn (fd, r, b, a, p);
        rr := rr + r;
        bb := bb + b;
        aa := aa + a;
        pp := pp + p;
     end;
  Close(fd);
  Assign (fr, rez);
  Rewrite (fr);
  WriteLn(fr, Procentai(pp, rr):0:2);
  WriteLn(fr, Procentai(pp, bb):0:2);
  WriteLn(fr, Procentai(pp, aa):0:2);
  Close (fr);
end.

