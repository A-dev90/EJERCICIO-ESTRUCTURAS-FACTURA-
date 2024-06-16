// ---------------------------------------------------DEBER FACTURA CON ESTRUCTURAS------------------------------------------------------
// CABECERA:  NOMBRE, RUC, N.CEDULA, DIORRCION, TELEFONO
// DETALLE DE FACTURA: CODIGO, NOMBRE DEL PRODUCTIO, CANTIDAD, PRECIO, VALOR TOTAL 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define IVA 0.15

struct direccion
{
    char ciudad[50];
    char sector[50];
    char calle_principal[100];
    char codigo_post[7];
};

struct cabecera
{
    char nombre_empresa[50];
    char ruc_empresa[20];
    char numero_factura[100];
    char fecha[11];
    char nombre_vendedor[50];
    char apellido_vendedor[50];
    char ID_vendedor[30];
    char nombre_cliente[100];
    char apellido_cliente[100];
    char cedula_cliente[15];
    struct direccion dir;
    char telefono_cliente[15];
    char correo [100];
};

struct detalle_compra1
{
    char codigo[50];
    char nombre_producto[100];
    int cantidad;
    float precio;
    float valor_total;
     

};
struct detalle_compra2
{
    char codigo[50];
    char nombre_producto[100];
    int cantidad;
    float precio;
    float valor_total;   

};


struct factura
{
   struct cabecera cab;
   struct detalle_compra1 compra1;
   struct detalle_compra2 compra2;
   float subtotal;
   float iva;
   float total_compra;

   
};



int main()
{
    struct factura fact=  {{"ECOMODA S.A",
                            "1726591876001",
                            "00010012",
                            "15/06/2024",
                            "Juan Diego",
                            "Lopez",
                            "A00231567",
                            "Ana Belen",
                            "Alvarez Carrasco",
                            "1714389895",
                            {"Quito", "Solanda", "AV. Mariscal Sucre", "180204"},
                            "0995312131",
                            "anabelen@gmail.com"},
                            {"A001",
                            "Jeans Algodon",
                            2,
                            15.50,
                            (15.50*2)},
                            {"B002",
                            "Camiseta Algodon",
                            3,
                            5.75,
                            (5.75*3)},
                            ((15.50*2)+(5.75*3)),
                            ((15.50*2)+(5.75*3))*IVA,
                            ((15.50*2)+(5.75*3))+(((15.50*2)+(5.75*3))*IVA),
                            };
    
    
    printf("\e[1;34m-----------------------------------------------------------------------\e[0m\n");
    printf("\e[1;34m                               FACTURA                            \e[0m\n");
    printf("\e[1;34m-----------------------------------------------------------------------\e[0m\n");
    printf("EMPRESA: %s\t\t\tRUC: %s\n\nNo.FACTURA: %s\n\nFECHA DE EMISION: %s\n\nDATOS VENDEDOR:\n\t\tNOMBRE: %s\n\n\t\tAPELLIDO: %s\n\n\t\tID: %s\n",fact.cab.nombre_empresa, fact.cab.ruc_empresa, fact.cab.numero_factura, fact.cab.fecha, fact.cab.nombre_vendedor, fact.cab.apellido_vendedor, fact.cab.ID_vendedor );
    
    printf("-----------------------------------------------------------------------\n");
    printf("\e[1;34m                          DATOS PERSONALES                           \e[0m\n");
    printf("-----------------------------------------------------------------------\n");
    printf("NOMBRE: %s\t\t\tAPELLIDOS: %s\n\nNo.CEDULA: %s\n\nDIRECCION:\n\t\tCIUDAD: %s\n\n\t\tSECTOR: %s\n\n\t\tCALLE PRINCIPAL: %s\n\n\t\tCODIGO POSTAL: %s\n\nCELULAR: %s\n\nCORREO ELECTRONICO: %s\n",fact.cab.nombre_cliente, fact.cab.apellido_cliente, fact.cab.cedula_cliente, fact.cab.dir.ciudad, fact.cab.dir.sector, fact.cab.dir.calle_principal, fact.cab.dir.codigo_post, fact.cab.telefono_cliente, fact.cab.correo  );

    printf("-----------------------------------------------------------------------\n");
    printf("\e[1;34m                          DETALLE DE COMPRA                            \e[0m\n");
    printf("-----------------------------------------------------------------------\n");
    printf("CODIGO: %s\t\t\tNOMBRE DEL PRODUCTO: %s\n\nCANTIDAD: %d\t\t\tPRECIO UNITARIO: %.2f\n\n\t\t\t\tVALOR TOTAL: %.2f\n\n\n", fact.compra1.codigo, fact.compra1.nombre_producto, fact.compra1.cantidad, fact.compra1.precio, fact.compra1.valor_total );
    printf("CODIGO: %s\t\t\tNOMBRE DEL PRODUCTO: %s\n\nCANTIDAD: %d\t\t\tPRECIO UNITARIO: %.2f\n\n\t\t\t\tVALOR TOTAL: %.2f\n\n\n-----------------------------------------------------------------------\nSUBTOTAL: %.2f\n\nIVA (15%%): %.2f\n\nTOTAL A PAGAR: %.2f\n\n", fact.compra2.codigo, fact.compra2.nombre_producto, fact.compra2.cantidad, fact.compra2.precio, fact.compra2.valor_total, fact.subtotal, fact.iva, fact.total_compra );
    printf("-----------------------------------------------------------------------\n");
    
    return 0;
}

