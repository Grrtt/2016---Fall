function getNav() {
    var docNav = document.getElementById('nav');
    docNav.innerHTML =
        '<ul>' +
            '<li><a href="MediaSearcher.html">Home</a></l>' + 
            '<li><a href="mediaList.html">Media</a></li>' +
            //'<li><a href="tvList.html">TV</a></li>' +
            '<li><a href="feedback.html">Feedback</a></li>' +
        '</ul>';
}



function loadList() {
    if (document.cookie === "") {
        document.cookie = "";
    } else {
        var a = [document.cookie.split()]
    }
}

function getMediaInfo() {
    var title = document.getElementById('title').value;
    var formattedTitle = title.replace(/\s+/g, "+");

    var year = document.getElementById('year').value;
    var plotLength = document.getElementById('plot').value;

    switch (plotLength) {
        case 'type1': plotLength = "full"; break;
        case 'type2': plotLength = "short"; break;
    }

    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open('GET', '//www.omdbapi.com/?' +
        't=' + formattedTitle +
        '&y=' + year +
        '&plot=' + plotLength +
        '&r=json' +
        '&tomatoes=true', true);
    xmlhttp.onreadystatechange = function () {
        if (xmlhttp.readyState == 4) {
            if (xmlhttp.status == 200) {
                var obj = JSON.parse(xmlhttp.responseText);
                if (obj.Error != "Movie not found!" && obj.Type != "game") {
                    var tableData = generateMediaTable(obj);
                    var parent = document.getElementById('content');
                    console.log(obj);
                    var tableID = document.getElementById(obj.imdbID);
                    console.log(obj.imdbID);
                    if (tableID == null) {
                        appendContent(tableData, obj, parent, obj.Type);
                    } else {
                        updateContent(tableData, obj.imdbID);
                        alert(obj.Title + " updated below.");
                    }
                    tableID = null;
                    
                } else if (obj.Type == "game"){
                    alert("Video game found.");
                } else {
                    alert("Media not found at IMDb.");
                }
            }
        }
    }
    xmlhttp.send(null);
}

function getMediaTrailer() {
    formattedTitle = title.replace(/\s+/g, "%20");
    console.log(formattedTitle);

    var xmlhttp = new XMLHttpRequest();
    xmlhttp.open('GET', 'http://trailersapi.com/trailers.json?' +
        'movie=' + formattedTitle +
        '&width=500', true);
    xmlhttp.onreadystatechange = function () {
        if (xmlhttp.readyState == 4) {
            if (xmlhttp.status == 200) {
                var obj = JSON.parse(xmlhttp.responseText);
                console.log(obj);
                var trailerElement = document.getElementById('trailer');
                updateContent(obj.code, trailerElement);
            }
        }
    }
}

function updateContent(data, elementID){
    var parent = document.getElementById(elementID);
    parent.innerHTML = data;
}

function appendContent(tableData, obj, parent, type) {
    var table = document.createElement("table");
    table.id = obj.imdbID;
    table.className = type;
    table.innerHTML = tableData;

    var element = document.getElementById('content');
    element.appendChild(table);
}

function formatTitle(title, replacementString) {
    var formattedText = title.replace(/\s+/g, replacementString);
    return formattedText;
}

function clearMedia() {
    var element = document.getElementById('content');
    element.innerHTML = null;
}

function generateMediaTable(obj) {
    var actors = obj.Actors;
    var awards = obj.Awards
    var country = obj.Country;
    var director = obj.Director;
    var genre = obj.Genre;
    var metascore = obj.Metascore;
    var plot = obj.Plot;
    var poster = obj.Poster;
    var rated = obj.Rated;
    var released = obj.Released;
    var response = obj.Response;
    var runtime = obj.Runtime;
    var title = obj.Title;

    var image = '';
    switch (obj.Type) {
        case "movie":
            image = '<img src="http://www.freeiconspng.com/uploads/movie-icon-2.png" alt="Movie." height="25" width="25">'
            obj.Type = "Movie";
            break;
        case "series":
            image = '<img src="https://cdn3.iconfinder.com/data/icons/tools-solid-icons-vol-2/72/88-512.png" alt="TV." height="25" width="25">'
            obj.Type = "TV";
            break;
        default:
            break;
    }
    var type = obj.Type;
    var writer = obj.Writer;
    var ID = obj.imdbID;
    var imdbRating = obj.imdbRating;
    var tomatoRating = obj.tomatoRating;
    var tomatoMeter = obj.tomatoMeter;
    var tomatoConsensus = obj.tomatoConsensus;

    var table =
        '<colgroup>' +
            '<col class="posterCol" />' + 
            '<col class="infoCol1" span="1" />' +
            '<col class="infoCol2" span="1" />' +
        '</colgroup>' +
        '<thead>' +
            '<tr>' +
                '<th id="title" title="Movie Title" colspan="4">'+ title +'</th>' +
            '</tr>' +
        '</thead>' +
        '<tbody>' +
            '<tr>' +
            '<td id="poster" title="Movie Poster" rowspan="5">' +
                '<img src="' + poster + '" alt="Error." height="268" width="182"/>' +
            '</td>' +
                '<td id="actors" title="Actor(s)">' + actors + '</td>' +
                '<td id="released" title="Release Date" colspan="2">' + released + '</td>' +
           '</tr>' +
           '<tr>' +
                '<td id="awards" title="Award(s)">' + awards + '</td>' +
                '<td id="rated" title="Movie Rating" colspan="2">' + rated + '</td>' +
            '</tr>' +
            '<tr>' +
                '<td id="director" title="Director(s)">' + director + '</td>' +
                '<td id="runtime" title="Runtime" colspan="2">' + runtime + '</td>' +
            '</tr>' +
            '<tr>' +
                '<td id="genre" title="Genre(s)">' + genre + '</td>' +
                '<td id="type" title="'+ type + '"colspan="2">' + image + '</td>' +
            '</tr>' +
            '<tr>' +
                '<td id="plot" title="Plot" colspan="3">' + plot + '</td>' +
            '</tr>' +
            '<tr>' +
                '<td colspan="3">' +
                '<table id="websites" class="websites">' +
                    '<thead>' +
                        '<tr>' +
                            '<th id="imdbInfo" title="IMDb Information" colspan="2"><a href="http://www.imdb.com/" target="_blank">IMDb</a></th>' +
                            '<th id="tomatoesInfo" title="Rotten Tomatoes Information" colspan="3"><a href="http://www.rottentomatoes.com/">Rotten Tomatoes</a></th>' +
                            '<th id="metacriticInfo" title="MetaCritic Information">metacritic</th>' +
                        '</tr>' +
                    '</thead>' +
                    '<tr>' +
                        '<td id="imdbID" title="IMDb ID"><a href="http://www.imdb.com/title/' + ID + '/" target="_blank">'+ ID +'</a></td>' +
                        '<td id="imdbRating" title="IMDb Rating">' + imdbRating + '</td>' +
                        '<td id="tomatoRating" title="Rotten Tomatoes Rating">' + tomatoRating + '</td>' +
                        '<td id="tomatoMeter" title="Tomato Meter">' + tomatoMeter + '</td>' +
                        '<td id="tomatoConsensus" title="Tomato Consensus">' + tomatoConsensus + '</td>' +
                        '<td id="metascore" title="MetaCritic Score">' + metascore + '</td>' +
                    '</tr>' +
                '</table>' +
                '</td>' +
            '</tr>' +
            
            /*
            '<tr>' +
                '<td id="trailer" colspan="4"></td>' +
            '</tr>' +
             */
        '</tbody>';

        return table;
}
