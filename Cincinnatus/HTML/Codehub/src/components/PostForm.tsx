import { useState, type FormEvent } from "react";
import type { Post } from "../types/Post";

type PostFormProps = {
  onCreatePost: (post: Omit<Post, "likes">) => void;
};

export function PostForm({ onCreatePost }: PostFormProps) {
  const [titulo, setTitulo] = useState("");
  const [descripcion, setDescripcion] = useState("");
  const [codigo, setCodigo] = useState("");

  const handleSubmit = (event: FormEvent<HTMLFormElement>) => {
    event.preventDefault();

    if (!titulo.trim() || !descripcion.trim() || !codigo.trim()) {
      return;
    }

    onCreatePost({ titulo, descripcion, codigo });

    setTitulo("");
    setDescripcion("");
    setCodigo("");
  };

  return (
    <form className="campos" onSubmit={handleSubmit}>
      <input
        type="text"
        value={titulo}
        onChange={(event) => setTitulo(event.target.value)}
        placeholder="Titulo"
      />

      <textarea
        value={descripcion}
        onChange={(event) => setDescripcion(event.target.value)}
        placeholder="README"
      />

      <textarea
        value={codigo}
        onChange={(event) => setCodigo(event.target.value)}
        placeholder="Codigo"
      />

      <button type="submit">Publicar</button>
    </form>
  );
}
