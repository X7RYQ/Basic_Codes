window.addEventListener('DOMContentLoaded', (event) => {

	const gSelect = document.getElementById('genre-list');
	const imdbID = document.getElementById('imdb');
	const langSelect = document.getElementById('language-list');
	const ratSelect = document.getElementById('rating-list');
	const ctrSelect = document.getElementById('country-list');
	const filBtn = document.getElementById('filter');
	const movieList = document.getElementById('movie-list');
	const errDiv = document.getElementById('error-message');
	const genres = [];
	const languages = [];
	const ratings = [];
	const countries = [];

	function showErr(msg) {
		errDiv.textContent = msg;
		errDiv.classList.remove("d-none");
	}

	function clearErr() {
		errDiv.classList.add("d-none");
	}

	movies.forEach(movie => {
		let movieGenres = movie.Genre.split(",").map(g => g.trim());
		let movieLang = movie.Language.split(",").map(l => l.trim());
		let movieRat = movie.Rated.split(",").map(r => r.trim());
		let movieCtr = movie.Country.split(",").map(c => c.trim());
		movieGenres.forEach(genre => {
			if (!genres.includes(genre)) {
				genres.push(genre);
			}
		})
		movieLang.forEach(lang => {
			if (!languages.includes(lang)) {
				languages.push(lang);
			}
		})
		movieRat.forEach(rating => {
			if (!ratings.includes(rating)) {
				ratings.push(rating);
			}
		})
		movieCtr.forEach(count => {
			if (!countries.includes(count)) {
				countries.push(count);
			}
		})
	})

	genres.sort();
	languages.sort();
	ratings.sort();
	countries.sort();

	genres.forEach(genre => {
		let option = document.createElement('option');
		option.value = genre;
		option.textContent = genre;
		gSelect.appendChild(option);
	});
	languages.forEach(lang => {
		let option = document.createElement('option');
		option.value = lang;
		option.textContent = lang;
		langSelect.appendChild(option);
	});
	ratings.forEach(rating => {
		let option = document.createElement('option');
		option.value = rating;
		option.textContent = rating;
		ratSelect.appendChild(option);
	});
	countries.forEach(country => {
		let option = document.createElement('option');
		option.value = country;
		option.textContent = country;
		ctrSelect.appendChild(option);
	});

	function displayMovies(filterM) {
		movieList.innerHTML = "";
		if (filterM.length === 0) {
			movieList.textContent = "No movies found";
			return;
		}

		filterM.forEach(movie => {
			let div = document.createElement('div');
			div.className = 'col-md-4 mb-3';
			div.innerHTML = `
                <div class="card h-100">
                    <div class="card-body">
                        <h2 class="card-title">${movie.Title}</h2>
						<p class="card-text">Year: ${movie.Year}</p>
                        <p class="card-text">Genre: ${movie.Genre}</p>
						<p class="card-text">IMDB Score: ${movie.imdbRating}</p>
                        <p class="card-text">Language: ${movie.Language}</p>
                        <p class="card-text">Rating: ${movie.Rated}</p>
                        <p class="card-text">Country: ${movie.Country}</p>
                    </div>
                </div>
            `;
			movieList.appendChild(div);
		});
	}

	function sortMovies(arr, type) {
		if (type === "title-asc") {
			arr.sort(function (a, b) {
				if (a.Title < b.Title) return -1;
				if (a.Title > b.Title) return 1;
				return 0;
			})
		}
		if (type === "title-desc") {
			arr.sort(function (a, b) {
				if (b.Title < a.Title) return -1;
				if (b.Title > a.Title) return 1;
				return 0;
			})
		}
		if (type === "year-asc") {
			arr.sort(function (a, b) {
				let sum = a.Year - b.Year;
				if (sum > 0) return 1;
				if (sum < 0) return -1;
				return 0;
			})
		}
		if (type === "year-desc") {
			arr.sort(function (a, b) {
				let sum = b.Year - a.Year;
				if (sum > 0) return 1;
				if (sum < 0) return -1;
				return 0;
			})
		}
		if (type === "imdb-asc") {
			arr.sort(function (a, b) {
				let sum = a.imdbRating - b.imdbRating;
				if (sum > 0) return 1;
				if (sum < 0) return -1;
				return 0;
			})
		}
		if (type === "imdb-desc") {
			arr.sort(function (a, b) {
				let sum = b.imdbRating - a.imdbRating;
				if (sum > 0) return 1;
				if (sum < 0) return -1;
				return 0;
			})
		}
	}

	filBtn.addEventListener('click', () => {
		const imdbSelect = parseFloat(imdbID.value);
		const fromID = document.getElementById('year-from');
		const fromY = parseInt(fromID.value);
		const toID = document.getElementById('year-to');
		const toY = parseInt(toID.value);
		const searchBar = document.getElementById('search');
		let searchValue = searchBar.value.toLowerCase();
		let sortRadio = document.querySelector('input[name="sort-order"]:checked');
		let sortOrder;
		let selectedG = gSelect.value;
		let selectedLang = langSelect.value;
		let selectedRat = ratSelect.value;
		let selectedCtr = ctrSelect.value;

		if (sortRadio !== null) {
			sortOrder = sortRadio.value;
		}

		if (fromY <= 0 || toY <= 0 || fromY > toY) {
			showErr("Invalid year range");
			return;
		}
		else {
			clearErr();
		}

		if (imdbSelect < 0.0 || isNaN(imdbSelect) && imdbSelect.length > 0 || imdbSelect > 10.0) {
			showErr("Invalid IMDB score");
			return;
		}
		else {
			clearErr();
		}
		const searchFilter = movies.filter(movie => {
			let selectSearch = true;
			if (searchValue.length >= 3) {
				let searchTitle = movie.Title.toLowerCase();
				let searchDirec = movie.Director.toLowerCase();
				let searchAct = movie.Actors.toLowerCase();
				selectSearch = searchTitle.includes(searchValue) || searchDirec.includes(searchValue) || searchAct.includes(searchValue);
			}
			let matchG = movie.Genre.includes(selectedG) || selectedG === "";
			let matchImdb = isNaN(imdbSelect) || movie.imdbRating >= imdbSelect;
			let matchYear = (isNaN(fromY) || movie.Year >= fromY) && (isNaN(toY) || movie.Year <= toY);
			let matchLang = movie.Language.includes(selectedLang) || selectedLang === "";
			let matchRat = movie.Rated.includes(selectedRat) || selectedRat === "";
			let matchCtr = movie.Country.includes(selectedCtr) || selectedCtr === "";
			return selectSearch && matchG && matchImdb && matchYear && matchLang && matchRat && matchCtr;
		});
		sortMovies(searchFilter, sortOrder);
		displayMovies(searchFilter);
	});
});
