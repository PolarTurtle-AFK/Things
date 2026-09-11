import { useEffect, useState } from 'react';
import { useSearchParams } from 'react-router-dom';

function Games() {
    const [searchParams, setSearchParams] = useSearchParams();
    const [games, setGames] = useState([]);

    const search = searchParams.get('search') || '';

    useEffect(() => {
        fetch(`http://localhost:3000/Games?search=${encodeURIComponent(search)}`)
            .then(response => response.json())
            .then(data => {
                console.log('Datos recibidos:', data);
                setGames(data);
            });
    }, [search]);

    return (
        <main className="games-page">
            <h1>Games</h1>

            <input
                className="search-bar"
                type="text"
                placeholder="Search games..."
                value={search}
                onChange={(event) => {
                    setSearchParams({
                        search: event.target.value
                    });
                }}
            />

            <div className="results">
                <pre>
                    {JSON.stringify(games, null, 4)}
                </pre>
            </div>

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
        </main>
    );
}

export default Games;