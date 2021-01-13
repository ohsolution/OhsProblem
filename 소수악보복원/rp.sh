SOL=sol
MKD=mkdata

for i in $(seq 1 100)
do
    ./$MKD > data/input$i.txt
    sleep 1
done

for i in $(seq 1 100)
do
    ./$SOL < data/input$i.txt > data/output$i.txt
done
