function Projects() {
    return (
        <main>
            <h1 className="name">Projects</h1>
            <p className="description">My projects</p>
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

export default Projects;