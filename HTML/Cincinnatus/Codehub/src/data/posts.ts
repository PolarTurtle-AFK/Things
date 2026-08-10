import type { Post } from "../types/Post";

export const initialPosts: Post[] = [
  {
    titulo: "Hola Mundo",
    descripcion: "Primer programa en C",
    codigo: `#include <stdio.h>

int main() {
    printf("Hola Mundo");
}`,
    likes: 0,
  },
  {
    titulo: "Suma",
    descripcion: "Función simple",
    codigo: `function suma(a, b) {
    return a + b;
}`,
    likes: 0,
  },
];
