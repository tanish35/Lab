DECLARE
    r NUMBER;
BEGIN
  r:=0;
  FOR i in 2..50 LOOP
    FOR j in 2..i-1 LOOP
      IF MOD(i,j)=0 THEN
        r:=1;
        EXIT;
      END IF;
    END LOOP;
    IF r=0 THEN
      dbms_output.put_line(i||' is prime');
    END IF;
    r:=0;
  END LOOP;
END;

