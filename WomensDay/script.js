var images = [
    "sources/1.jpg",
    "sources/2.jpg",
    "sources/3.jpg",
  ];
  
  var slideshowImage = document.getElementById("slideshow-image")
  var currentImageIndex = 0
  
  function showSlideshow() {
    var fullscreen = document.getElementById("fullscreen")
    var closeBtn = document.getElementById("close-btn")
  
    // Show the fullscreen elements
    fullscreen.style.display = "block"
    closeBtn.style.display = "block"
  
    // Set the first image as the slideshow image
    slideshowImage.src = images[currentImageIndex]
    slideshowImage.style.opacity = 1
  
    // Advance to the next image every 5 seconds
    setInterval(function() {
      // Fade out the current image
      slideshowImage.style.opacity = 0
  
      setTimeout(function() {
        currentImageIndex = (currentImageIndex + 1) % images.length
        slideshowImage.src = images[currentImageIndex]
  
        // Fade in the next image
        slideshowImage.style.opacity = 1
      }, 1000)
    }, 5000)
  }
  
  function exitFullScreen() {
    var fullscreen = document.getElementById("fullscreen")
    var closeBtn = document.getElementById("close-btn")
    fullscreen.style.display = "none"
    closeBtn.style.display = "none"
  }