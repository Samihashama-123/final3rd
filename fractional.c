#include<stdio.h>
/* eikhane amra ekta item struct banaisi ja ekta 
item er value,weight store kore*/
struct item{
    int weight;    
    int value;
}; 
 /*Eita ekta helper function ja item gula ke value/weight ratio
  onujayi descending order e sort kore.*/ 
void sortItems(struct item items[], int n){ 
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
//Ei line e item i and item j er value-to-weight ratio ber kora hocche.
            float r1= (float)items[i].value/items[i].weight;
            float r2= (float)items[j].value/items[j].weight;
/*Jodi r1 choto hoy, tahole item[j] er ratio beshi. 
Tai amra swap kore boro ratio wala item ke age niye ashi.*/
            if(r1<r2){
                struct item temp = items[i];
                       items[i]=items[j];
                       items[j] = temp;
            }
        }
    }
}
float fractionalKnapsack (struct item items[], int n, int capacity)
{
    //Prothome items gula ke sort kore value/weight ratio onujayi.
    sortItems(items, n);
    //Bag e total value rakhar jonno variable.initially 0 dhora hoyese
    float totalValue = 0.0;
    for(int i=0; i<n; i++){
        if(capacity==0) //Jodi bag full hoye jay (capacity = 0), loop bondho.
        break;
    //Jodi puro item nite pari, niye ni, capacity theke minus kore value add kore dao.
        if(items[i].weight<=capacity){
            capacity -= items[i].weight; 
            totalValue += items[i].value;
        }
   /*Jodi full item nite na pari, je poriman capacity ache, 
   tar upor base kore fractional value nite hobe.*/
        else{
            float fraction =(float)capacity/items[i].weight;
            totalValue += items[i].value * fraction;
            capacity =0;
        }
    }
    return totalValue;
};
int main(){
    int n,capacity;
    printf("Enter number of items:");
    scanf("%d", &n);
    // User theke input nei n ta item er jonno array banai.
    struct item items[n];
    for(int i=0; i<n; i++){
        printf("Enter value and weight of items %d:", i+1);
        //Each item er value & weight input.
        scanf("%d%d", &items[i].value, &items[i].weight);
    }
    printf("Enter knapsack capacity:");
    scanf("%d", &capacity);
    //Fractional knapsack function call kore max value print kori.
    float maxValue = fractionalKnapsack(items, n, capacity);
    printf("Maximum value of knapsack=  %.2f\n", maxValue);
    return 0;
}
