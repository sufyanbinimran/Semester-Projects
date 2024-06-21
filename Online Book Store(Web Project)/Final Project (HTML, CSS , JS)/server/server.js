const express = require('express');
const mongoose = require('mongoose');
const bcrypt = require('bcrypt');
const nodemailer = require('nodemailer');
const bodyParser = require("body-parser");
const { v4: uuidv4 } = require('uuid');



const app = express();

// Connect to MongoDB
mongoose.connect('mongodb://localhost:27017/Darsi-Book-bazar', {
  useNewUrlParser: true,
  useUnifiedTopology: true
}).then(() => {
  console.log('Connected to MongoDB');
}).catch(err => {
  console.error('Error connecting to MongoDB:', err);
});

// Define a mongoose schema for the user
const userSchema = new mongoose.Schema({
  firstName: String,
  lastName: String,
  email: String,
  password: String
});

// Create a mongoose model for the users collection
const User = mongoose.model('users', userSchema);

// Create a Nodemailer transporter
const transporter = nodemailer.createTransport({
  service: 'Gmail',
  auth: {
    user: 'sufyanbinimran@gmail.com',
    pass: 'ixdt bhcw tose lgeh' // Replace with your actual email password
  }
});

// Middleware for parsing JSON and URL-encoded data
app.use(express.json());
app.use(express.urlencoded({ extended: true }));

// Route for handling sign up form submission
app.post('/signup', async (req, res) => {
  const { firstName, lastName, email, password } = req.body;

  // Hash the password
  const hashedPassword = await bcrypt.hash(password, 10);

  // Create a new user instance
  const newUser = new User({
    firstName,
    lastName,
    email,
    password: hashedPassword
  });

  // Save the user to the database
  newUser.save()
    .then(() => {
      console.log('User saved successfully');
      res.status(201).send('User saved successfully');
    })
    .catch(err => {
      console.error('Error saving user:', err);
      res.status(500).send('Error saving user');
    });
});

// Route for handling login requests
app.post('/login', async (req, res) => {
  const { email, password } = req.body;

  try {
    // Find user by email
    const user = await User.findOne({ email });
    if (!user) {
      // User not found
      return res.status(404).send('User not found');
    }

    // Check if password matches
    const passwordMatch = await bcrypt.compare(password, user.password);
    if (!passwordMatch) {
      // Password doesn't match
      return res.status(401).send('Invalid password');
    }

    // Authentication successful
    // Send email to the user
    const mailOptions = {
      from: 'sufyanbinimran@gmail.com',
      to: email,
      subject: 'Login Notification',
      text: 'You have successfully logged in to your account.'
    };

    transporter.sendMail(mailOptions, (error, info) => {
      if (error) {
        console.error('Error sending email:', error);
        res.status(500).send('Error sending email');
      } else {
        console.log('Email sent:', info.response);
        res.status(200).send('Login successful. Email sent.');
      }
    });
  } catch (err) {
    console.error('Error during login:', err);
    res.status(500).send('Internal server error');
  }
});
////////////////////////////////////////////////////////
// Route for handling subscription requests
app.post('/subscribe', async (req, res) => {
  const { email } = req.body;

  try {
    // Send email to the user
    const mailOptions = {
      from: 'sufyanbinimran@gmail.com',
      to: email,
      subject: 'Subscription Confirmation',
      text: 'Thank you for subscribing to our newsletter! Stay tuned for the latest arrivals and updates.'
    };

    await transporter.sendMail(mailOptions);
    
    res.status(200).send('Subscription successful. Email sent.');
  } catch (error) {
    console.error('Error sending email:', error);
    res.status(500).send('Error sending email');
  }
});
////////////////////////////////////////////////////////
// Connect to MongoDB
mongoose.connect('mongodb://localhost:27017/Darsi-Book-bazar', { useNewUrlParser: true, useUnifiedTopology: true });

// Define schema
const otpSchema = new mongoose.Schema({
  email: { type: String, required: true },
  otp: { type: Number, required: true }
});

// Define model
const OTP = mongoose.model('OTP', otpSchema);
// Generate random OTP
function generateOTP() {
  return Math.floor(1000 + Math.random() * 9000);
}

// Express route to handle form submission
app.post('/forget', async (req, res) => {
  const email = req.body.email;
  const otp = generateOTP();

  try {
    // Insert OTP into database
    await OTP.create({ email, otp });

    // Nodemailer setup
    const transporter = nodemailer.createTransport({
      service: 'gmail',
      auth: {
        user: 'sufyanbinimran@gmail.com', // Update with your email
        pass: 'ixdt bhcw tose lgeh' // Update with your password
      }
    });

    const mailOptions = {
      from: 'sufyanbinimran@gmail.com', // Update with your email
      to: email,
      subject: 'Your OTP for Login',
      text: `Your OTP is: ${otp}`
    };

    // Send email with OTP
    transporter.sendMail(mailOptions, (error, info) => {
      if (error) {
        console.log(error);
        res.status(500).send('Failed to send OTP.');
      } else {
        console.log('Email sent: ' + info.response);
        res.status(200).send('OTP sent successfully.');
      }
    });
  } catch (error) {
    console.error('Error:', error);
    res.status(500).send('Failed to generate OTP.');
  }
});

app.post('/verify-otp', async (req, res) => {
  const email = req.body.email;
  const enteredOTP = req.body.otp;

  try {
    // Find the OTP document for the given email
    const otpDocument = await OTP.findOne({ email });

    if (!otpDocument) {
      // No OTP found for the email
      res.status(400).send('Invalid email or OTP');
      return;
    }

    // Compare the entered OTP with the one stored in the database
    if (enteredOTP === otpDocument.otp.toString()) {
      // OTP matches, login successful
      res.status(200).send('Login successful!');
    } else {
      // Incorrect OTP
      res.status(400).send('Incorrect OTP');
    }
  } catch (error) {
    console.error('Error:', error);
    res.status(500).send('Failed to verify OTP');
  }
});

// Start the server on port 3000
const port = 3000;
app.listen(port, () => {
  console.log(`Server is running on port ${port}`);
});