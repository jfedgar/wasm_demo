const express = require('express');
const app = express();

// serve static files from public dir
app.use(express.static('public', {
  setHeaders: (res, path, stat) => {
    //serve .wasm files with correct content type
    if (path.endsWith('.wasm')) {
      res.set('Content-Type', 'application/wasm');
    }
  }
}));

app.listen(2222, () => console.log("server running on port 2222"));