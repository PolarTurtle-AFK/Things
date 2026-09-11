function Home() {
    return (
        <main>
            <h1 className="name">PolarTurtle</h1>
            <p className="description">Software Engineering student & developer</p>
            <div className="menu">
                <a href="/games" className="card">
                    Games
                </a>

                <a href="/" className="card">
                    Home
                </a>
                
                <a href="/projects" className="card">
                    Projects
                </a>
            </div>
            <footer>
                <p>&copy; 2026 PolarTurtle. All rights reserved.</p>
            </footer>
        </main>
    );
}

export default Home;