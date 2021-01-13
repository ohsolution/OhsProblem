USR=user

for i in $(seq 1 100)
do
    ./$USR < data/input$i.txt > data/userout$i.txt
done

for i in $(seq 1 100)
do
    diff -bsq data/output$i.txt data/userout$i.txt >> result.txt
done

rm data/userout*
