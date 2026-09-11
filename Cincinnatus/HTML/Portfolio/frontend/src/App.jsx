import { BrowserRouter, Routes, Route } from 'react-router-dom';

import Home from './pages/Home';
import Games from './pages/Games';
import Projects from './pages/Projects';

function App() {
    return (
        <BrowserRouter>
            <Routes>
                <Route path="/" element={<Home />} />
                <Route path="/games" element={<Games />} />
                <Route path="/projects" element={<Projects />} />
            </Routes>
        </BrowserRouter>
    );
}

export default App;