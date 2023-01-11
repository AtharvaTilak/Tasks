import React from "react";
import { BrowserRouter as Router, Route, NavLink } from "react-router-dom";
import DefaultChart from "./default-chart/default-chart";


import "./App.css";

const App = () => {
  return (
    <Router>
      <div className="wrapper">
            Default Chart
        <Route path="/default-chart" component={DefaultChart} />
      </div>
    </Router>
  );
};

export default App;
