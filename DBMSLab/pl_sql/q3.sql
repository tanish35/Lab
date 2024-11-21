DECLARE
    total NUMBER ;
BEGIN
  total:=0;
  FOR i in 1..20 LOOP
    total:=total+i;
  END LOOP;
  dbms_output.put_line('The total is '||total);
END;

