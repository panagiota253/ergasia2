// dimiourgia ths domhs proiontos kai tou katalogou
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define num_products 5//5 proionta
#define num_client 3//3 pelates
#define num_orders 5 //kathe pelaths kanei 5 paraggelies

//domh proiontos
typedef struct {
   char description[50]; //perigrafh proiontos
   float price; //timh proiontos
   int stock; //diathesima temaxia
 } product;

//katalogos me ta diathesima proionta
product catalog[num_products]= {
   {"laptop",800.0,2}
   {"smartphone",400.0,5}
   {"headphones",50.0,10}
   {"tablet",300.0,3}
   {"smartwatch",150.0,4}
};
//epejergasia ths paraggelias apo ton ejipirethth
void process_order(int read_fd,int write_fd)
   int product_id;
   char response[100];

read(read_fd, &product_id, sizeof(int)); //diavazoume to proion apo ton pelath
if (product_id>=0 && product_id < num_products){//elegxoume to id tou proiontos na rinai megalutro h' iso me tp 0 kai entos tou aritmou proiontwn 
   Product *product = &catalog[product_id];

if (product->stock >0) //an iparxei diathesimo proion
   printf(response, "order successful: %s, price: %.2f, product->description,product->price);
   product->stock--; //meiwnoume to apothema
} else {
         printf(response,"order failed:%s is out of stock", product->description);
} else {
         printf(response,"invalid product selection");
}
write(write_fd,response,strlen(response) +1); //apostolh apanthshs ston pelath mesw tou 2ou pipe
}
//kwdikas pelath gia thn apostolh paraggeliwn
void client(int client_fd,int *pipe_fds)
   for (int i = 0;i < num_orders;i++) {
          int product_id = rand() % num_products;  // epilogh tyxaiou proiontos
//stelnoume thn paraggelia mesw pipe
    write(pipe_fds[client_id * 2], &product_id, sizeof(int));
// diavazoume thn apanthsh apo ton ejipirethth
        char response[100];
        read(pipe_fds[client_id * 2 + 1], response, sizeof(response));
        printf("Client %d: %s\n", client_id, response);
//anamonh gia ena deyterolepto prin thn epomenh paraggelia
   sleep(1);
  }
}
int main() //patrikh diergasia (apo ton ejipirethth)
{
    int pipe_fds[num_clients * 2];  // 2 pipes  gia kathe pelath , dhladh aithma kai apanthsh


//dimiourgia twn pipes gia thn epikoinwnia
    for (int i = 0;i < num_clients;i++) {
        pipe(pipe_fds + i * 2); // Pipe gia apostolh paraggelias
        pipe(pipe_fds + i * 2 + 1); // Pipe gia apostolh apanthshs
    }
//dimiourgia twn pelatwn mesw fork()
    for (int i = 0;i < num_clients;i++) {
         pid_t pid = fork();
        
        if (pid==0) 
// kwdikas gia pelath
  client(i, pipe_fds);
  exit(0);  // o pelaths termatizei
  }
}
//ejipirethsh paraggeliwn 

    for (int i = 0;i < num_clients;i++) {

//o ejipirethths diavazei tis paraggelies kai tis epejergazetai
    int product_id;
    read(pipe_fds[i * 2], &product_id, sizeof(int));
// kaloume th synarthsh gia na epejergastoume thn paraggelia
   process_order(pipe_fds[i * 2], pipe_fds[i * 2 + 1]);
}
  for (int i = 0; i < num_clients; i++) {
      wait(NULL); //anamonh gia thn oloklhrwsh twn thigatrikwn ergassiwn(pelatwn)
    }
    return 0;
}




