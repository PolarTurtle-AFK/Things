import type { Post } from "../types/Post";

type PostCardProps = {
  post: Post;
  onLike: () => void;
  onCopy: () => void;
};

export function PostCard({ post, onLike, onCopy }: PostCardProps) {
  return (
    <article className="post">
      <h2>{post.titulo}</h2>
      <p>{post.descripcion}</p>
      <pre>{post.codigo}</pre>

      <div className="botones">
        <button className="copiar" type="button" onClick={onCopy}>
          Copiar
        </button>
        <button className="like" type="button" onClick={onLike}>
          {post.likes} Likes
        </button>
      </div>
    </article>
  );
}
