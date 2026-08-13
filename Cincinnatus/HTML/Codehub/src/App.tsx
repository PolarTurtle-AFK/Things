import { useState } from "react";
import { PostForm } from "./components/PostForm";
import { PostList } from "./components/PostList";
import { initialPosts } from "./data/posts";
import type { Post } from "./types/Post";

export default function App() {
  const [posts, setPosts] = useState<Post[]>(initialPosts);

  const handleCreatePost = (post: Omit<Post, "likes">) => {
    setPosts((currentPosts) => [
      ...currentPosts,
      {
        ...post,
        likes: 0,
      },
    ]);
  };

  const handleLikePost = (index: number) => {
    setPosts((currentPosts) =>
      currentPosts.map((post, currentIndex) =>
        currentIndex === index
          ? { ...post, likes: post.likes + 1 }
          : post
      )
    );
  };

  const handleCopyCode = async (code: string) => {
    await navigator.clipboard.writeText(code);
    alert("Codigo copiado");
  };

  return (
    <main className="app">
      <header className="titulo">
        <h1>CodeShare</h1>
        <p className="subtitulo">
          Comparte tus proyectos
        </p>
      </header>

      <section className="formulario">
        <PostForm onCreatePost={handleCreatePost} />
      </section>

      <section className="posts">
        <PostList
          posts={posts}
          onLikePost={handleLikePost}
          onCopyCode={handleCopyCode}
        />
      </section>
    </main>
  );
}
