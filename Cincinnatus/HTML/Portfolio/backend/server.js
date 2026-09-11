const express = require('express');
const cors = require('cors');

const app = express();

app.use(cors());

const routerGames = require('./routers/Games.js');

app.use('/Games', routerGames);

app.get('/', (req, res) => {
    res.send('Server is running');
});

const PUERTO = 3000;

app.listen(PUERTO, () => {
    console.log('Server is running on port ' + PUERTO);
});