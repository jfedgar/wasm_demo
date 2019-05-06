const express = require('express');
const app = express();

// serve static files from public dir
app.use(express.static('public'));

app.listen(2222, () => console.log("server running on port 2222"));