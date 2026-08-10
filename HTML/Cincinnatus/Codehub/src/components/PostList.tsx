import { PostCard } from "./PostCard";
import type { Post } from "../types/Post";

type PostListProps = {
  posts: Post[];
  onLikePost: (index: number) => void;
  onCopyCode: (code: string) => void;
};

export function PostList({ posts, onLikePost, onCopyCode }: PostListProps) {
  return (
    <div className="lista-posts">
      {posts.map((post, index) => (
        <PostCard
          key={`${post.titulo}-${index}`}
          post={post}
          onLike={() => onLikePost(index)}
          onCopy={() => onCopyCode(post.codigo)}
        />
      ))}
    </div>
  );
}
