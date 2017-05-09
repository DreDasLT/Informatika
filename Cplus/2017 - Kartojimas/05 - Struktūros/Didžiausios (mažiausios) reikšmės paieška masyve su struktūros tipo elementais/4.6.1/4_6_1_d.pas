program Ilgiausia_kelione;
  const  duom = 'Duomenys.txt';
  const  rez = 'Rezultatai.txt';
  type Marsrutas = array[1..100] of string[15];
       Marsrutai = record
                      pav : string[15];
                        t : integer;
                   end;
      Masyvas1 = array[1..100] of Marsrutai;
//---------------------------------------------
      Etapas = record
                      pav : string[20];
                    t, tt : integer;
                        M : Marsrutas;
                   end;
      Masyvas2 = array[1..100] of Etapas;
//-------------------------------------------------
function Didziausia(M : Masyvas1; t : integer) : integer;
   var i, d : integer;
begin
   d := 1;
   for i := 1 to t do
    if M[i].t > M[d].t then d := i;
    Didziausia := d;
end;
//-------------------------------------------------
procedure Skaitymas (var E : Masyvas2; var n : integer);
   var          i, j : integer;
          v, m, d, t : integer;
                   MM : Masyvas1;
                  fd : text;
begin
  Assign (fd, duom);
  Reset (fd);
  ReadLn (fd, n);
  for i := 1 to n do
    begin
       ReadLn (fd, E[i].pav, t);
       for j := 1 to t do
         begin
           Read (fd, MM[j].pav);
           ReadLn (fd, v, m);
           MM[j].t := v * 60 + m;
         end;
        d := Didziausia (MM, t);
        E[i].tt := 0;
        for j := 1 to t do
         if MM[j].t = MM[d].t
           then
             begin
               E[i].tt := E[i].tt + 1;
               E[i].M[E[i].tt] := MM[j].pav;
               E[i].t := MM[j].t;
             end;
       end;
  Close (fd);
end;
//--------------------------------------------------
procedure Rasymas(E : Masyvas2; n : integer);
   var fr : text; i, j : integer;
begin
  Assign (fr, rez);
  Rewrite (fr);
  for i := 1 to n do
     begin
        WriteLn (fr, E[i].pav, ' ', E[i].t div 60, ' ', E[i].t mod 60);
        for j := 1 to E[i].tt do
           WriteLn (fr, E[i].M[j]);
     end;
  Close (fr);
end;
//-------------------------------------------------
   var       n : integer;
             E : Masyvas2;
begin
  Skaitymas(E, n);
  Rasymas(E, n);
end.
