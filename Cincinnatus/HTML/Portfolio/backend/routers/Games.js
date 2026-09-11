const express = require('express');
const { infoGames } = require('../data/infoGames.js');

const router = express.Router();

router.get('/', (req, res) => {
    console.log('Received request for games with search query:', req.query.search);


    const search = req.query.search;

    if (!search) {
        return res.json(infoGames);
    }

    const results = infoGames.filter(game =>
        Object.values(game).some(value =>
            String(value).toLowerCase().includes(search.toLowerCase())
        )
    );

    res.json(results);
});

module.exports = router;